/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    WIN_ONE,
    WIN_TWO
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_LOPTN,
    KC_ROPTN,
    KC_LCMMD,
    KC_RCMMD,
    KC_SIRI,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
    KC_SCREEN_SHOT,
    KC_CORTANA
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER
#define KC_SNAP KC_SCREEN_SHOT
#define KC_CRTA KC_CORTANA

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[3];
} key_combination_t;

key_combination_t key_comb_list[4] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}},
    {3, {KC_LSFT, KC_LCMD, KC_4}},
    {2, {KC_LWIN, KC_C}}
};

static uint8_t mac_keycode[4] = { KC_LOPT, KC_ROPT, KC_LCMD, KC_RCMD };

enum unicode_names {
    ALPHA, BETA, GAMMA, GGAMMA, DELTA, DDELTA, EPSILON, ZETA, ETA, THETA, TTHETA, IOTA, KAPPA, LAMBDA, LLAMBDA,
    MU, NU, XI, XXI, PI, PPI, RHO, SIGMA, SSIGMA, TAU, UPSILON, PHI, PPHI, XHI, PSI, PPSI, OMEGA, OOMEGA,

    U_9, U_0, U_LB, U_RB
};

const uint32_t PROGMEM unicode_map[] = {
    [ALPHA] = 0x03B1, [BETA] = 0x03B2, [GAMMA] = 0x03B3, [GGAMMA] = 0x0393, [DELTA] = 0x03B4, [DDELTA] = 0x0394,
    [EPSILON] = 0x03B5, [ZETA] = 0x03B6, [ETA] = 0x03B7, [THETA] = 0x03B8, [TTHETA] = 0x0398, [IOTA] = 0x03B9,
    [KAPPA] = 0x03BA, [LAMBDA] = 0x03BB, [LLAMBDA] = 0x039B, [MU] = 0x03BC, [NU] = 0x03BD, [XI] = 0x03BE,
    [XXI] = 0x039E, [PI] = 0x03C0, [PPI] = 0x03A0, [RHO] = 0x03C1, [SIGMA] = 0x03C3, [SSIGMA] = 0x03A3,
    [TAU] = 0x03C4, [UPSILON] = 0x03C5, [PHI] = 0x03C6, [PPHI] = 0x03A6, [XHI] = 0x03C7,
    [PSI] = 0x03C8, [PPSI] = 0x03A8, [OMEGA] = 0x03C9, [OOMEGA] = 0x03A9,

    [U_9] = 0x39, [U_0] = 0x30, [U_LB] = 0x5B, [U_RB] = 0x5D
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_all(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_VOLD, KC_MUTE, KC_VOLU, KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN,MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_all(
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_VAD, RGB_TOG, RGB_VAI, KC_TRNS,  KC_TRNS,  RGB_TOG,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    [WIN_BASE] = LAYOUT_all(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,    KC_VOLD,  KC_MUTE,  KC_VOLU,  KC_MPRV,  KC_MNXT, KC_PSCR,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,    KC_BSPC,  KC_DEL,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        CAPSWRD,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,             KC_ENT,
        KC_LSPO,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSPC,            KC_UP,
        KC_LCPO,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  TG(WIN_ONE), TG(WIN_FN), KC_RCPC,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_all(
        KC_TRNS,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,   KC_WH_U,  TG(WIN_ONE),  KC_WH_D,  KC_TRNS,  KC_MPLY,  KC_WSCH,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,             KC_TRNS,            KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    [WIN_ONE] = LAYOUT_all(
        KC_TRNS,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,     KC_TRNS, KC_TRNS, KC_LEFT, KC_TRNS, KC_RIGHT,   KC_TRNS, KC_TRNS, UC_MOD,
        KC_TRNS,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,     KC_TRNS,          KC_TRNS,
        KC_LSFT,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,                       KC_RSFT,                              KC_TRNS,
        KC_TRNS,  KC_TRNS,       KC_TRNS,                                             KC_TRNS,                                                    KC_TRNS,             TO(WIN_BASE),         KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS,  KC_TRNS),

    [WIN_TWO] = LAYOUT_all(
        KC_TRNS,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, UC_MOD,
        KC_TRNS,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,     KC_TRNS,          KC_TRNS,
        KC_LSFT,  KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,       KC_TRNS,           KC_TRNS,           KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,                       KC_RSFT,                              KC_TRNS,
        KC_TRNS,  KC_TRNS,       KC_TRNS,                                             KC_TRNS,                                                    KC_TRNS,             TO(WIN_BASE),         KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS,  KC_TRNS)
};

uint16_t prev;
bool siri;

void matrix_scan_user(void) {
    if (siri) {
        if (timer_elapsed(prev) >= 500) {
            siri = false;
            unregister_code(KC_LCMD);
            unregister_code(KC_SPACE);
        }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LOPTN:
        case KC_ROPTN:
        case KC_LCMMD:
        case KC_RCMMD:
            if (record->event.pressed) {
                register_code(mac_keycode[keycode - KC_LOPTN]);
            } else {
                unregister_code(mac_keycode[keycode - KC_LOPTN]);
            }
            return false;  // Skip all further processing of this key
        case KC_SIRI:
            if (record->event.pressed) {
                register_code(KC_LCMD);
                register_code(KC_SPACE);
                prev = timer_read() | 1;
                siri = true;
            } else {
                // Do something else when release
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
        case KC_SNAP:
        case KC_CRTA:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}
