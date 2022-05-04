module.exports = grammar({
    name: 'norg2',

    conflicts: $ => [
        [$.paragraph],

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
            ),
        ),

        word: $ => /[a-zA-Z0-9]+/,
        space: $ => /[\t\v ]+/,

        line_break: _ => token.immediate('\n'),

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

        quote1: $ => gen_quote($, 1),
        quote2: $ => gen_quote($, 2),
        quote3: $ => gen_quote($, 3),
        quote4: $ => gen_quote($, 4),
        quote5: $ => gen_quote($, 5),
        quote6: $ => gen_quote($, 6),

    }
});

function gen_quote($, level) {
    lower_level_quotes = [];

    for (let i = 0; i + level < 6; i++) {
        lower_level_quotes[i] = $["quote" + (i + 1 + level)]
    }

    return seq(
        optional($.carryover_tag),

        token.immediate('>'.repeat(level) + ' '),

        $.paragraph,

        repeat(
            choice(
                ...lower_level_quotes,
            ),
        ),
    );
}
