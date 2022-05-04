module.exports = grammar({
    name: 'norg2',

    conflicts: $ => [
        [$.paragraph],
        [$.paragraph, $.paragraph_break],

        [$.quote1],
        [$.quote2],
        [$.quote3],
        [$.quote4],
        [$.quote5],
        [$.quote6],
    ],

    rules: {
        document: $ => repeat(
            choice(
                $.quote,
                $.paragraph,
                alias($.paragraph_break, "_paragraph_break"),
            ),
        ),

        word: _ => /[a-zA-Z0-9]+/,
        space: _ => /[\t\v ]+/,
        punctuation: _ => /[\.,]/,

        line_break: _ => token.immediate(/[\n\r]/),
        paragraph_break: $ => prec.dynamic(2,
            seq(
                alias($.line_break, "_line_break"),
                alias($.line_break, "_line_break"),
            ),
        ),

        // Any regular text. A paragraph is made up of `paragraph_segment`
        // objects and line breaks.
        paragraph: $ =>
            seq(
                // optional(
                //     $.infecting_tag_set,
                // ),
                repeat1(
                    choice(
                        $.paragraph_segment,
                        alias($.line_break, "_line_break"),
                    ),
                ),
            ),

        // A paragraph segment can contain any paragraph element.
        paragraph_segment: $ =>
        prec.right(0,
            seq(
                // optional($.carryover_tag_set),
                repeat1(
                    choice(
                        $._paragraph_element,
                    ),
                ),
            ),
        ),

        // Any of the following choices are valid IN-LINE elements. Any
        // multitude of these are combined to form a `paragraph_segment`.
        _paragraph_element: $ =>
        choice(
            alias($.word, "_word"),
            alias($.space, "_space"),
            alias($.punctuation, "_punctuation"),
        ),

        carryover_tag: $ =>
        seq(
            token.immediate('+'),
            alias($.word, "tag_name"),
            alias($.line_break, "_line_break"),
        ),

        quote: $ => prec.right(
            repeat1(
                choice(
                    $.quote1,
                    $.quote2,
                    $.quote3,
                    $.quote4,
                    $.quote5,
                    $.quote6,
                ),
            ),
        ),

        quote1_prefix: $ => gen_quote_prefix($, 1),
        quote2_prefix: $ => gen_quote_prefix($, 2),
        quote3_prefix: $ => gen_quote_prefix($, 3),
        quote4_prefix: $ => gen_quote_prefix($, 4),
        quote5_prefix: $ => gen_quote_prefix($, 5),
        quote6_prefix: $ => gen_quote_prefix($, 6),
        quote1: $ => gen_quote($, 1),
        quote2: $ => gen_quote($, 2),
        quote3: $ => gen_quote($, 3),
        quote4: $ => gen_quote($, 4),
        quote5: $ => gen_quote($, 5),
        quote6: $ => gen_quote($, 6),

    }
});

function gen_quote_prefix($, level) {
    if (level == 6) {
        return seq(
            token.immediate('>'.repeat(level)),
            repeat(
                token.immediate('>'),
            ),
            token.immediate(' '),
        );
    }
    return token.immediate('>'.repeat(level) + ' ');
}

function gen_quote($, level) {
    lower_level_quotes = [];

    for (let i = 0; i + level < 6; i++) {
        lower_level_quotes[i] = $["quote" + (i + 1 + level)]
    }

    return seq(
        optional($.carryover_tag),

        $["quote" + level + "_prefix"],

        field(
            "content",
            $.paragraph,
        ),

        repeat(
            choice(
                ...lower_level_quotes,
            ),
        ),
    );
}
