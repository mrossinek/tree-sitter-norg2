module.exports = grammar({
    name: 'norg2',

    conflicts: $ => [
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

        repeat1(
            choice(
                alias($.word, "_word"),
                alias($.line_break, "_line_break"),
            ),
        ),

        repeat(
            choice(
                ...lower_level_quotes,
            ),
        ),
    );
}
