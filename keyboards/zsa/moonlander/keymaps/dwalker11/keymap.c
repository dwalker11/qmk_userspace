/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
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
#include "version.h"

enum layers {
    BASE,  // default layer
    NAV,   // navigation layer
    SYMB,  // symbols
    NUM,   // numbers
    MDIA,  // media keys
    GAME,  // reset base layer
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// Escape Control
#define CTL_ESC CTL_T(KC_ESC)

// Left-hand layer-tap mods
#define NAV_A LT(NAV,KC_A)
#define SYMB_F LT(SYMB,KC_F)

// Shift Curly Brackets
#define LSFT_CBR LSFT_T(KC_LCBR)
#define RSFT_CBR RSFT_T(KC_RCBR)

// Right-hand home-row mods
#define GUI_J RGUI_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_GRV,   KC_1,    KC_2,      KC_3,    KC_4,     KC_5,   XXXXXXX,        XXXXXXX,  KC_6,   KC_7,    KC_8,    KC_9,     KC_0,      KC_BSPC,
        KC_TAB,   KC_Q,    KC_W,      KC_E,    KC_R,     KC_T,   KC_MEH,         KC_LGUI,  KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,      KC_BSLS,
        OS_LCTL,  NAV_A,   KC_S,      KC_D,    SYMB_F,   KC_G,   KC_HYPR,        KC_LCTL,  KC_H,   GUI_J,   SFT_K,   ALT_L,    CTL_SCLN,  KC_QUOT,
        LSFT_CBR, KC_Z,    KC_X,      KC_C,    KC_V,     KC_B,                             KC_N,   KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   RSFT_CBR,
        CW_TOGG,  TG(NUM), OSL(MDIA), KC_LEFT, KC_RGHT,          CTL_ESC,        KC_ENT,           KC_DOWN, KC_UP,   TG(GAME), OSL(SYMB), KC_DEL,
                                               KC_SPC,  OS_LSFT, OS_LGUI,        OS_LCTL, OS_LALT, KC_SPC
    ),

    [NAV] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,   _______, KC_F12,
        _______, _______, _______, _______, KC_LSFT, _______, _______,           _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, QK_LLCK, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______,  _______, _______,
                                            _______, KC_LCTL, _______,           _______, KC_LALT, _______
    ),

    [SYMB] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,           _______, _______, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_PIPE,
        _______, KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_LPRN, _______,           _______, KC_RPRN, KC_MINS, KC_EQL,  _______, _______, KC_GRV,
        KC_LCBR, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, KC_BSLS, KC_RCBR,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______,           _______, _______, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______,           _______, _______, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,                             _______, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, KC_0,    KC_DOT,  KC_EQL,  _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [MDIA] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, RM_HUED, RM_SATD, RM_VALD, RM_PREV, _______, _______,           _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, QK_RBT,
        _______, RM_HUEU, RM_SATU, RM_VALU, RM_NEXT, _______, _______,           _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______, _______,
        _______, _______, _______, _______, RM_TOGG, _______,                             _______, AU_TOGG, MU_TOGG, MU_NEXT, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    [GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_A,    _______, _______, KC_F,    _______, _______,           _______, _______, KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
        KC_LSFT, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, KC_RSFT,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
