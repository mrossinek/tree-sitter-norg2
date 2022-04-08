module.exports = grammar({
    name: 'norg2',

    conflicts: $ => [
        [$.quote1],
        [$.quote2],
    ],

    rules: {
        document: $ => repeat(
            choice(
                $.quote,
            ),
        ),

        word: $ => /[a-zA-Z0-9]+/,

        line_break: _ => token.immediate('\n'),

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
                ),
            ),
        ),

        quote1: $ => prec.dynamic(1,
            seq(
                optional($.carryover_tag),

                token.immediate('> '),

                repeat1(
                    choice(
                        alias($.word, "_word"),
                        alias($.line_break, "_line_break"),
                    ),
                ),

                repeat(
                    choice(
                        $.quote2,
                    ),
                ),
            ),
        ),

        quote2: $ => prec.dynamic(1,
            seq(
                optional($.carryover_tag),

                token.immediate('>> '),
                repeat1(
                    choice(
                        alias($.word, "_word"),
                        alias($.line_break, "_line_break"),
                    ),
                ),
            ),
        ),

    }
});
