#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 25
#define LARGE_STATE_COUNT 8
#define SYMBOL_COUNT 15
#define ALIAS_COUNT 1
#define TOKEN_COUNT 6
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 2

enum {
  sym_word = 1,
  sym_line_break = 2,
  anon_sym_PLUS = 3,
  anon_sym_GT = 4,
  anon_sym_GT_GT = 5,
  sym_document = 6,
  sym_carryover_tag = 7,
  sym_quote = 8,
  sym_quote1 = 9,
  sym_quote2 = 10,
  aux_sym_document_repeat1 = 11,
  aux_sym_quote_repeat1 = 12,
  aux_sym_quote1_repeat1 = 13,
  aux_sym_quote1_repeat2 = 14,
  anon_alias_sym__word = 15,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_word] = "tag_name",
  [sym_line_break] = "_line_break",
  [anon_sym_PLUS] = "+",
  [anon_sym_GT] = "> ",
  [anon_sym_GT_GT] = ">> ",
  [sym_document] = "document",
  [sym_carryover_tag] = "carryover_tag",
  [sym_quote] = "quote",
  [sym_quote1] = "quote1",
  [sym_quote2] = "quote2",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_quote_repeat1] = "quote_repeat1",
  [aux_sym_quote1_repeat1] = "quote1_repeat1",
  [aux_sym_quote1_repeat2] = "quote1_repeat2",
  [anon_alias_sym__word] = "_word",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_word] = sym_word,
  [sym_line_break] = sym_line_break,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [sym_document] = sym_document,
  [sym_carryover_tag] = sym_carryover_tag,
  [sym_quote] = sym_quote,
  [sym_quote1] = sym_quote1,
  [sym_quote2] = sym_quote2,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_quote_repeat1] = aux_sym_quote_repeat1,
  [aux_sym_quote1_repeat1] = aux_sym_quote1_repeat1,
  [aux_sym_quote1_repeat2] = aux_sym_quote1_repeat2,
  [anon_alias_sym__word] = anon_alias_sym__word,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_word] = {
    .visible = true,
    .named = false,
  },
  [sym_line_break] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_carryover_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_quote] = {
    .visible = true,
    .named = true,
  },
  [sym_quote1] = {
    .visible = true,
    .named = true,
  },
  [sym_quote2] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quote_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quote1_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_quote1_repeat2] = {
    .visible = false,
    .named = false,
  },
  [anon_alias_sym__word] = {
    .visible = true,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = anon_alias_sym__word,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(5);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '+') ADVANCE(8);
      if (lookahead == '>') ADVANCE(1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(6);
      END_STATE();
    case 1:
      if (lookahead == ' ') ADVANCE(9);
      if (lookahead == '>') ADVANCE(2);
      END_STATE();
    case 2:
      if (lookahead == ' ') ADVANCE(10);
      END_STATE();
    case 3:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(6);
      END_STATE();
    case 4:
      if (eof) ADVANCE(5);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(6);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(sym_word);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(6);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_line_break);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 3},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_word] = ACTIONS(1),
    [sym_line_break] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(24),
    [sym_carryover_tag] = STATE(19),
    [sym_quote] = STATE(3),
    [sym_quote1] = STATE(6),
    [sym_quote2] = STATE(6),
    [aux_sym_document_repeat1] = STATE(3),
    [aux_sym_quote_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_PLUS] = ACTIONS(5),
    [anon_sym_GT] = ACTIONS(7),
    [anon_sym_GT_GT] = ACTIONS(9),
  },
  [2] = {
    [sym_carryover_tag] = STATE(21),
    [sym_quote2] = STATE(8),
    [aux_sym_quote1_repeat1] = STATE(12),
    [aux_sym_quote1_repeat2] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(11),
    [sym_word] = ACTIONS(13),
    [sym_line_break] = ACTIONS(15),
    [anon_sym_PLUS] = ACTIONS(17),
    [anon_sym_GT] = ACTIONS(11),
    [anon_sym_GT_GT] = ACTIONS(20),
  },
  [3] = {
    [sym_carryover_tag] = STATE(19),
    [sym_quote] = STATE(5),
    [sym_quote1] = STATE(6),
    [sym_quote2] = STATE(6),
    [aux_sym_document_repeat1] = STATE(5),
    [aux_sym_quote_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(23),
    [anon_sym_PLUS] = ACTIONS(5),
    [anon_sym_GT] = ACTIONS(7),
    [anon_sym_GT_GT] = ACTIONS(9),
  },
  [4] = {
    [sym_carryover_tag] = STATE(21),
    [sym_quote2] = STATE(13),
    [aux_sym_quote1_repeat1] = STATE(12),
    [aux_sym_quote1_repeat2] = STATE(13),
    [ts_builtin_sym_end] = ACTIONS(25),
    [sym_word] = ACTIONS(13),
    [sym_line_break] = ACTIONS(15),
    [anon_sym_PLUS] = ACTIONS(27),
    [anon_sym_GT] = ACTIONS(25),
    [anon_sym_GT_GT] = ACTIONS(30),
  },
  [5] = {
    [sym_carryover_tag] = STATE(19),
    [sym_quote] = STATE(5),
    [sym_quote1] = STATE(6),
    [sym_quote2] = STATE(6),
    [aux_sym_document_repeat1] = STATE(5),
    [aux_sym_quote_repeat1] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(33),
    [anon_sym_PLUS] = ACTIONS(35),
    [anon_sym_GT] = ACTIONS(38),
    [anon_sym_GT_GT] = ACTIONS(41),
  },
  [6] = {
    [sym_carryover_tag] = STATE(19),
    [sym_quote1] = STATE(7),
    [sym_quote2] = STATE(7),
    [aux_sym_quote_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(44),
    [anon_sym_PLUS] = ACTIONS(5),
    [anon_sym_GT] = ACTIONS(7),
    [anon_sym_GT_GT] = ACTIONS(9),
  },
  [7] = {
    [sym_carryover_tag] = STATE(19),
    [sym_quote1] = STATE(7),
    [sym_quote2] = STATE(7),
    [aux_sym_quote_repeat1] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(46),
    [anon_sym_PLUS] = ACTIONS(48),
    [anon_sym_GT] = ACTIONS(51),
    [anon_sym_GT_GT] = ACTIONS(54),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(59), 1,
      anon_sym_PLUS,
    ACTIONS(62), 1,
      anon_sym_GT_GT,
    STATE(21), 1,
      sym_carryover_tag,
    ACTIONS(57), 2,
      ts_builtin_sym_end,
      anon_sym_GT,
    STATE(9), 2,
      sym_quote2,
      aux_sym_quote1_repeat2,
  [18] = 5,
    ACTIONS(67), 1,
      anon_sym_PLUS,
    ACTIONS(70), 1,
      anon_sym_GT_GT,
    STATE(21), 1,
      sym_carryover_tag,
    ACTIONS(65), 2,
      ts_builtin_sym_end,
      anon_sym_GT,
    STATE(9), 2,
      sym_quote2,
      aux_sym_quote1_repeat2,
  [36] = 4,
    ACTIONS(13), 1,
      sym_word,
    ACTIONS(15), 1,
      sym_line_break,
    STATE(12), 1,
      aux_sym_quote1_repeat1,
    ACTIONS(73), 4,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_GT,
      anon_sym_GT_GT,
  [52] = 4,
    ACTIONS(13), 1,
      sym_word,
    ACTIONS(15), 1,
      sym_line_break,
    STATE(12), 1,
      aux_sym_quote1_repeat1,
    ACTIONS(75), 4,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_GT,
      anon_sym_GT_GT,
  [68] = 4,
    ACTIONS(79), 1,
      sym_word,
    ACTIONS(82), 1,
      sym_line_break,
    STATE(12), 1,
      aux_sym_quote1_repeat1,
    ACTIONS(77), 4,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_GT,
      anon_sym_GT_GT,
  [84] = 5,
    ACTIONS(17), 1,
      anon_sym_PLUS,
    ACTIONS(20), 1,
      anon_sym_GT_GT,
    STATE(21), 1,
      sym_carryover_tag,
    ACTIONS(11), 2,
      ts_builtin_sym_end,
      anon_sym_GT,
    STATE(9), 2,
      sym_quote2,
      aux_sym_quote1_repeat2,
  [102] = 2,
    ACTIONS(87), 1,
      sym_word,
    ACTIONS(85), 5,
      ts_builtin_sym_end,
      sym_line_break,
      anon_sym_PLUS,
      anon_sym_GT,
      anon_sym_GT_GT,
  [113] = 3,
    ACTIONS(13), 1,
      sym_word,
    ACTIONS(89), 1,
      sym_line_break,
    STATE(4), 1,
      aux_sym_quote1_repeat1,
  [123] = 3,
    ACTIONS(13), 1,
      sym_word,
    ACTIONS(91), 1,
      sym_line_break,
    STATE(11), 1,
      aux_sym_quote1_repeat1,
  [133] = 3,
    ACTIONS(13), 1,
      sym_word,
    ACTIONS(93), 1,
      sym_line_break,
    STATE(2), 1,
      aux_sym_quote1_repeat1,
  [143] = 3,
    ACTIONS(13), 1,
      sym_word,
    ACTIONS(95), 1,
      sym_line_break,
    STATE(10), 1,
      aux_sym_quote1_repeat1,
  [153] = 2,
    ACTIONS(97), 1,
      anon_sym_GT,
    ACTIONS(99), 1,
      anon_sym_GT_GT,
  [160] = 1,
    ACTIONS(101), 2,
      anon_sym_GT,
      anon_sym_GT_GT,
  [165] = 1,
    ACTIONS(99), 1,
      anon_sym_GT_GT,
  [169] = 1,
    ACTIONS(103), 1,
      sym_word,
  [173] = 1,
    ACTIONS(105), 1,
      sym_line_break,
  [177] = 1,
    ACTIONS(107), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(8)] = 0,
  [SMALL_STATE(9)] = 18,
  [SMALL_STATE(10)] = 36,
  [SMALL_STATE(11)] = 52,
  [SMALL_STATE(12)] = 68,
  [SMALL_STATE(13)] = 84,
  [SMALL_STATE(14)] = 102,
  [SMALL_STATE(15)] = 113,
  [SMALL_STATE(16)] = 123,
  [SMALL_STATE(17)] = 133,
  [SMALL_STATE(18)] = 143,
  [SMALL_STATE(19)] = 153,
  [SMALL_STATE(20)] = 160,
  [SMALL_STATE(21)] = 165,
  [SMALL_STATE(22)] = 169,
  [SMALL_STATE(23)] = 173,
  [SMALL_STATE(24)] = 177,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote1, 3, .dynamic_precedence = 1),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_quote1, 3, .dynamic_precedence = 1), SHIFT(22),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_quote1, 3, .dynamic_precedence = 1), SHIFT(16),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote1, 2, .dynamic_precedence = 1),
  [27] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_quote1, 2, .dynamic_precedence = 1), SHIFT(22),
  [30] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_quote1, 2, .dynamic_precedence = 1), SHIFT(16),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(22),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(15),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(16),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote, 1),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quote_repeat1, 2),
  [48] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quote_repeat1, 2), SHIFT_REPEAT(22),
  [51] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quote_repeat1, 2), SHIFT_REPEAT(15),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quote_repeat1, 2), SHIFT_REPEAT(16),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote1, 4, .dynamic_precedence = 1),
  [59] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_quote1, 4, .dynamic_precedence = 1), SHIFT(22),
  [62] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_quote1, 4, .dynamic_precedence = 1), SHIFT(16),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quote1_repeat2, 2),
  [67] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quote1_repeat2, 2), SHIFT_REPEAT(22),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quote1_repeat2, 2), SHIFT_REPEAT(16),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote2, 3, .dynamic_precedence = 1),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote2, 2, .dynamic_precedence = 1),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quote1_repeat1, 2),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_quote1_repeat1, 2), SHIFT_REPEAT(14),
  [82] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_quote1_repeat1, 2), SHIFT_REPEAT(12),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_quote1_repeat1, 1, .production_id = 1),
  [87] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_quote1_repeat1, 1, .production_id = 1),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [101] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_carryover_tag, 3),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [107] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_norg2(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
