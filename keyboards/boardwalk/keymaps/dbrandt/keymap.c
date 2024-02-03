/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_swedish_pro_osx_iso.h"

// Tap dance declarations
enum {
  TD_AR,
  TD_AD,
  TD_OD,
  TD_SAR,
  TD_SAD,
  TD_SOD,
  TD_ESC,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  // double-tap A for Å, E for Ä and O for Ö
  [TD_AR] = ACTION_TAP_DANCE_DOUBLE(SE_A, SE_ARNG),
  [TD_AD] = ACTION_TAP_DANCE_DOUBLE(SE_E, SE_ADIA),
  [TD_OD] = ACTION_TAP_DANCE_DOUBLE(SE_O, SE_ODIA),
  [TD_SAR] = ACTION_TAP_DANCE_DOUBLE(S(SE_A), S(SE_ARNG)),
  [TD_SAD] = ACTION_TAP_DANCE_DOUBLE(S(SE_E), S(SE_ADIA)),
  [TD_SOD] = ACTION_TAP_DANCE_DOUBLE(S(SE_O), S(SE_ODIA)),
  [TD_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, ALGR(SE_DIAE)),
};


// Layer shorthand
enum layer_names {
    _BASE,
    _SHIFT,
    _FN,
};

// Redefine things that don't work out of the box
#define LBRC ALGR(SE_8)     // [
#define RBRC ALGR(SE_9)     // ]
#define LCBR S(ALGR(SE_8))  // {
#define RCBR S(ALGR(SE_9))  // }
#define AT ALGR(SE_2)       // @
#define DLR ALGR(SE_4)      // $

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E/Ä    | R      | T      | [      | ]      | Y      | U      | I      | O/Ö    | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | LCTRL  | A/Å    | S      | D      | F      | G      | HOME   | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | FN     | LALT   | SPACE  | SPACE  | SPACE  | SPACE  | SPACE  | LEFT   | DOWN   | UP     | RIGHT  | RCTRL  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_ortho_5x14(
	TD(TD_ESC), SE_1,      SE_2,    SE_3,      SE_4,    SE_5,    SE_MINS, SE_EQL,  SE_6,    SE_7,    SE_8,    SE_9,      SE_0,    KC_BSPC,
        KC_TAB,     SE_Q,      SE_W,    TD(TD_AD), SE_R,    SE_T,    LBRC,    RBRC,    SE_Y,    SE_U,    SE_I,    TD(TD_OD), SE_P,    SE_QUOT,
        KC_LCTL,    TD(TD_AR), SE_S,    SE_D,      SE_F,    SE_G,    KC_HOME, KC_PGUP, SE_H,    SE_J,    SE_K,    SE_L,      SE_SCLN, KC_ENT,
        MO(_SHIFT), SE_Z,      SE_X,    SE_C,      SE_V,    SE_B,    KC_END,  KC_PGDN, SE_N,    SE_M,    SE_COMM, SE_DOT,    SE_SLSH, MO(_SHIFT),
        KC_LCTL,    KC_LGUI,   MO(_FN), KC_LALT,   KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT, KC_RCTL
    ),

    /* Shifted Base Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | !      | @      | #      | $      | %      | _      | +      | ^      | &      | *      | (      | )      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | {      | }      | Y      | U      | I      | O      | P      | "      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | LCTRL  | A      | S      | D      | F      | G      | (      | )      | H      | J      | K      | L      | :      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | \      | |      | N      | M      | <      | >      | ?      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | FN     | LALT   | SPACE  | SPACE  | SPACE  | SPACE  | SPACE  | LEFT   | DOWN   | UP     | RIGHT  | RCTRL  |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_SHIFT] = LAYOUT_ortho_5x14(
        SE_GRV,  SE_EXLM,    AT,      SE_HASH,    DLR,     SE_PERC, SE_UNDS, SE_PLUS, SE_CIRC, SE_AMPR, SE_ASTR, SE_LPRN,    SE_RPRN, KC_BSPC,
        KC_TAB,  S(SE_Q),    S(SE_W), TD(TD_SAD), S(SE_R), S(SE_T), LCBR,    RCBR,    S(SE_Y), S(SE_U), S(SE_I), TD(TD_SOD), S(SE_P), SE_DQUO,
	KC_LCTL, TD(TD_SAR), S(SE_S), S(SE_D),    S(SE_F), S(SE_G), SE_LPRN, SE_RPRN, S(SE_H), S(SE_J), S(SE_K), S(SE_L),    SE_COLN, KC_ENT,
	KC_LSFT, S(SE_Z),    S(SE_X), S(SE_C),    S(SE_V), S(SE_B), LBRC,    RBRC,    S(SE_N), S(SE_M), SE_LABK, SE_RABK,    SE_QUES, KC_RSFT,
        KC_LCTL, KC_LGUI,    MO(_FN), KC_LALT,    KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,      KC_RGHT, KC_RCTL
    ),

    /* Function Layer
     * .-----------------------------------------------------------------------------------------------------------------------------.
     * | `      | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | DEL    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * |        |        | MENU   |        |        |        |        |        | RGBFWD | RGBHUI | RGBSAI | RGBVAI | PRT SC |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * |        |        |        |        |        |        |        |        | RGBREV | RGBHUD | RGBSAD | RGBVAD |        | RESET  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * |        |        |        |        |        |        |        |        |        | MUTE   | VOL DN | VOL UP |        |        |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
     * |        |        |        |        |        |        |        |        |        | PLAY   | NEXT   | PREV   |        |        |
     * '-----------------------------------------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ortho_5x14(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,
        _______, _______, KC_APP,  _______, _______, _______, _______, _______, RGB_MOD,  RGB_HUI, RGB_SAI,  RGB_VAI, KC_PSCR, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_RMOD, RGB_HUD, RGB_SAD,  RGB_VAD, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_MUTE, KC_VOLD,  KC_VOLU, KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_MPLY,  KC_MPRV, KC_MNXT, _______, _______
    )

};
