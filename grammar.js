module.exports = grammar({
    name: 'norg2',

    inline: $ => [
        $.heading,
    ],

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
                $.heading,
                $.quote,
                $.paragraph,
                alias($.paragraph_break, "_paragraph_break"),
            ),
        ),

        word: _ => /[a-zA-Z0-9]+/,
        space: _ => /[\t\v ]+/,
        punctuation: _ => /[\.,]/,

        line_break: _ => token.immediate(/[\n\r]/),
        paragraph_break: $ => prec.dynamic(1,
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
            $.bold,
        ),

        bold: $ =>
        prec.left(3,
            seq(
                token.immediate('*'),
                prec.right(1,
                    repeat1(
                        choice(
                            $._paragraph_element,
                            alias($.line_break, "_line_break"),
                        ),
                    ),
                ),
                token.immediate('*'),
            ),
        ),

        carryover_tag: $ =>
        seq(
            token.immediate('+'),
            alias($.word, "tag_name"),
            alias($.line_break, "_line_break"),
        ),

        heading: $ => choice(
            $.heading1,
            $.heading2,
            $.heading3,
            $.heading4,
            $.heading5,
            $.heading6,
        ),


        heading1_prefix: $ => gen_heading_prefix($, 1),
        heading2_prefix: $ => gen_heading_prefix($, 2),
        heading3_prefix: $ => gen_heading_prefix($, 3),
        heading4_prefix: $ => gen_heading_prefix($, 4),
        heading5_prefix: $ => gen_heading_prefix($, 5),
        heading6_prefix: $ => gen_heading_prefix($, 6),
        heading1: $ => gen_heading($, 1),
        heading2: $ => gen_heading($, 2),
        heading3: $ => gen_heading($, 3),
        heading4: $ => gen_heading($, 4),
        heading5: $ => gen_heading($, 5),
        heading6: $ => gen_heading($, 6),

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

function gen_detached_mod_prefix($, icon, level) {
    if (level == 6) {
        return seq(
            token.immediate(icon.repeat(level)),
            repeat(
                token.immediate(icon),
            ),
            token.immediate(' '),
        );
    }
    return token.immediate(icon.repeat(level) + ' ');
}

function gen_heading_prefix($, level) {
    return gen_detached_mod_prefix($, '*', level);
}

function gen_heading($, level) {
    lower_level_headings = [];

    for (let i = 0; i + level < 6; i++) {
        lower_level_headings[i] = $["heading" + (i + 1 + level)]
    }

    return prec.right(0,
        seq(
            optional($.carryover_tag),

            $["heading" + level + "_prefix"],

            field(
                "title",
                $.paragraph_segment,
            ),

            repeat(
                prec(1,
                    alias($.line_break, "_line_break"),
                ),
            ),

            field(
                "content",
                repeat(
                    choice(
                        $.paragraph,
                        $.quote,

                        ...lower_level_headings,
                    ),
                ),
            ),
        ),
    );
}

function gen_quote_prefix($, level) {
    return gen_detached_mod_prefix($, '>', level);
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
