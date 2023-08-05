/* Copyright 2022 splitkb.com <support@splitkb.com>
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

#define _MAIN 0
#define _MAIN_WIN 1
#define _SYM_NUM 2
#define _SYM_NUM_WIN 3
#define _SYM_FN 4
#define _SYM_FN_WIN 5
#define _GAME 6
#define _GAME_NUM 7
#define _MEDIA 8
#define _MEDIA_WIN 9
#define _SYS_MOU 10
#define _SYS_ARR 11
#define _SYS_MOU_WIN 12
#define _SYS_ARR_WIN 13

#define _MK 14
#define _SYS_ARR_MK 15

#define MEHS MEH_T(KC_SPC)
#define OLSFT OSM(MOD_LSFT)
#define OLCTL OSM(MOD_LCTL)
#define OLGUI OSM(MOD_LGUI)
#define OLALT OSM(MOD_LALT)

#define SYSA OSL(_SYS_ARR)
#define SYMN OSL(_SYM_NUM)
#define SYMF OSL(_SYM_FN)
#define TMAIN TO(_MAIN)
#define TSYSA TO(_SYS_ARR)
#define TSYSM TO(_SYS_MOU)
#define TMEDI TO(_MEDIA)

#define SYSAW OSL(_SYS_ARR_WIN)
#define SYMNW OSL(_SYM_NUM_WIN)
#define SYMFW OSL(_SYM_FN_WIN)
#define TMAINW TO(_MAIN_WIN)
#define TSYSAW TO(_SYS_ARR_WIN)
#define TSYSMW TO(_SYS_MOU_WIN)
#define TMEDIW TO(_MEDIA_WIN)

//gaming PUBG
#define GAMEN TT(_GAME_NUM)
#define TGAME TO(_GAME)

//monkeytype WIN
#define TMK TO(_MK)
#define SYSARRMK OSL(_SYS_ARR_MK)

//Tap Dance Declarations
#define TD_TN 0 
#define TD_46 1
#define TD_37 2
#define TD_9H 3

tap_dance_action_t tap_dance_actions[] = {
  [TD_TN] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_N),
  [TD_46] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_6),
  [TD_37] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_7),
  [TD_9H] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_H),
};

//Combos
const uint16_t PROGMEM combo_sysm[] = {MEHS, OLSFT, COMBO_END};

const uint16_t PROGMEM combo_mac_symf[] = {SYSA, SYMN, COMBO_END};
const uint16_t PROGMEM combo_mac_lang[] = {SYSA, OLSFT, COMBO_END};
const uint16_t PROGMEM combo_mac_medi[] = {MEHS, SYMN, COMBO_END};

const uint16_t PROGMEM combo_win_symf[] = {SYSAW, SYMNW, COMBO_END};
const uint16_t PROGMEM combo_win_lang[] = {SYSAW, OLSFT, COMBO_END};
const uint16_t PROGMEM combo_win_medi[] = {MEHS, SYMNW, COMBO_END};


combo_t key_combos[] = { 
    COMBO(combo_sysm, TSYSM),

    COMBO(combo_mac_lang, LGUI(KC_SPC)),
    COMBO(combo_mac_symf, SYMF),
    COMBO(combo_mac_medi, TMEDI),

    COMBO(combo_win_symf, SYMFW),
    COMBO(combo_win_lang, LGUI(KC_SPC)),
    COMBO(combo_win_medi, TMEDIW),
};

//Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ Y        │ C        │ L        │ M        │ K        │   │ Z        │ F        │ U        │ Q        │ X        │
    KC_Y     , KC_C     , KC_L     , KC_M     , KC_K     ,     KC_Z     , KC_F     , KC_U     , KC_Q     , KC_X     ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ I        │ S        │ R        │ T        │ G        │   │ P        │ N        │ E        │ A        │ O        │
    KC_I     , KC_S     , KC_R     , KC_T     , KC_G     ,     KC_P     , KC_N     , KC_E     , KC_A     , KC_O     ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ V        │ W        │ D        │ J        │   │ B        │ H        │ ,        │ .        │          │
    KC_NO    , KC_V     , KC_W     , KC_D     , KC_J     ,     KC_B     , KC_H     , KC_COMMA , KC_DOT   , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ MEH & SPC│ ->SYS-ARR│   │ ->SYM-NUM│OSM LSHIFT│
        		             MEHS     , SYSA     ,     SYMN     , OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
    ),
    [_MAIN_WIN] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ Y        │ C        │ L        │ M        │ K        │   │ Z        │ F        │ U        │ Q        │ X        │
    KC_Y     , KC_C     , KC_L     , KC_M     , KC_K     ,     KC_Z     , KC_F     , KC_U     , KC_Q     , KC_X     ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ I        │ S        │ R        │ T        │ G        │   │ P        │ N        │ E        │ A        │ O        │
    KC_I     , KC_S     , KC_R     , KC_T     , KC_G     ,     KC_P     , KC_N     , KC_E     , KC_A     , KC_O     ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ V        │ W        │ D        │ J        │   │ B        │ H        │ ,        │ .        │          │
    KC_NO    , KC_V     , KC_W     , KC_D     , KC_J     ,     KC_B     , KC_H     , KC_COMMA , KC_DOT   , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ MEH & SPC│ ->SYS-ARR│   │ ->SYM-NUM│OSM LSHIFT│
        		             MEHS     , SYSAW    ,     SYMNW    , OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
    ),
    [_SYM_NUM] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ 1        │ 2        │ 3        │ 4        │ 5        │   │ 6        │ 7        │ 8        │ 9        │ 0        │
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,     KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ %        │ {        │ (        │ [        │ _        │   │ -        │ /        │ !        │ ~        │ =        │
    KC_PERC  , KC_LCBR  , KC_LPRN  , KC_LBRC  , KC_UNDS  ,     KC_PMNS  , KC_SLSH  , KC_EXLM  , KC_TILD  , KC_PEQL  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ }        │ )        │ ]        │ *        │   │ +        │ '        │ ;        │ &        │          │
    KC_NO    , KC_RCBR  , KC_RPRN  , KC_RBRC  , KC_PAST  ,     KC_PPLS  , KC_QUOT  , KC_SCLN  , KC_AMPR  , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ ->MAIN   │ ->SYS-ARR│   │ ->SYM-FN │OSM LSHIFT│
        			     TMAIN    , SYSA     ,     SYMF     , OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
    [_SYM_NUM_WIN] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ 1        │ 2        │ 3        │ 4        │ 5        │   │ 6        │ 7        │ 8        │ 9        │ 0        │
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,     KC_6     , KC_7     , KC_8     , KC_9     , KC_0     ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ %        │ {        │ (        │ [        │ _        │   │ -        │ /        │ !        │ ~        │ =        │
    KC_PERC  , KC_LCBR  , KC_LPRN  , KC_LBRC  , KC_UNDS  ,     KC_PMNS  , KC_SLSH  , KC_EXLM  , KC_TILD  , KC_PEQL  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ }        │ )        │ ]        │ *        │   │ +        │ '        │ ;        │ &        │          │
    KC_NO    , KC_RCBR  , KC_RPRN  , KC_RBRC  , KC_PAST  ,     KC_PPLS  , KC_QUOT  , KC_SCLN  , KC_AMPR  , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ ->MAIN   │ ->SYS-ARR│   │ ->SYM-FN │OSM LSHIFT│
        			     TMAINW   , SYSAW    ,     SYMFW    , OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
    [_SYM_FN] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ F1       │ F2       │ FL       │ F4       │ F5       │   │ F6       │ F7       │ F8       │ F9       │ F10      │
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,     KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ TAB      │ OSM LCTRL│ OSM LALT │ OSM LGUI │ DELETE   │   │          │ \        │ |        │          │ F11      │
    KC_TAB   , OLCTL    , OLALT    , OLGUI    , KC_DEL   ,     KC_NO    , KC_BSLS  , KC_PIPE  , KC_NO    , KC_F11   ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │          │          │          │ ENTER    │   │          │ `        │ ^        │ F12      │          │
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_ENT   ,     KC_NO    , KC_GRV   , KC_CIRC  , KC_F12   , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ ->MAIN   │ ->SYS-ARR│   │ ->SYM-NUM│OSM LSHIFT│
         			     TMAIN    , SYSA     ,     SYMN     , OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
     [_SYM_FN_WIN] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ F1       │ F2       │ FL       │ F4       │ F5       │   │ F6       │ F7       │ F8       │ F9       │ F10      │
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,     KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ TAB      │ OSM LGUI │ OSM LALT │ OSM LCTRL│ DELETE   │   │          │ \        │ |        │          │ F11      │
    KC_TAB   , OLGUI    , OLALT    , OLCTL    , KC_DEL   ,     KC_NO    , KC_BSLS  , KC_PIPE  , KC_NO    , KC_F11   ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │          │          │          │ ENTER    │   │          │ `        │ ^        │ F12      │          │
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_ENT   ,     KC_NO    , KC_GRV   , KC_CIRC  , KC_F12   , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ ->MAIN   │ ->SYS-ARR│   │ ->SYM-NUM│OSM LSHIFT│
         			     TMAINW   , SYSAW    ,     SYMNW    , OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
    [_GAME] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ TAB      │ Q        │ W        │ E        │ R        │   │ Y        │ U        │ I        │ PAGE UP  │ ESC      │
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     ,     KC_Y     , KC_U     , KC_I     , KC_PGUP  , KC_ESC   ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ L SHIFT  │ A        │ S        │ D        │ F        │   │ H        │ J        │ K        │ PAGE DOWN│ ENTER    │
    KC_LSFT  , KC_A     , KC_S     , KC_D     , KC_F     ,     KC_H     , KC_J     , KC_K     , KC_PGDN  , KC_ENT   ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ Z        │ X        │ C        │ V        │   │ N        │ M        │ ,        │ .        │          │
    KC_NO    , KC_Z     , KC_X     , KC_C     , KC_V     ,     KC_N     , KC_M     , KC_COMMA , KC_DOT   , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ SPACE    │ ->GAM-NUM│   │          │ ->MAIN   │
         		             KC_SPC   , GAMEN    ,     KC_NO    , TMAINW
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
    [_GAME_NUM] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ 5        │ 4 & 6    │ W        │ 3 & 7    │ T & N    │   │ Y        │ U        │ I        │ PAGE UP  │ ESC      │
    KC_5     , TD(TD_46), KC_W     , TD(TD_37), TD(TD_TN),     KC_Y     , KC_U     , KC_I     , KC_PGUP  , KC_ESC   ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ L CTRL   │ A        │ S        │ D        │ G        │   │ H        │ J        │ K        │ PAGE DOWN│ BACKSPACE│
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_G     ,     KC_H     , KC_J     , KC_K     , KC_PGDN  , KC_BSPC  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ 8        │ 9 & H    │ 0        │ B        │   │ N        │ M        │ ,        │ .        │          │
    KC_NO    , KC_8     , TD(TD_9H), KC_0     , KC_B     ,     KC_N     , KC_M     , KC_COMMA , KC_DOT   , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ L ALT    │ ->GAME   │   │          │          │
         		     	     KC_LALT  , TGAME    ,     KC_NO    , KC_NO
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
    [_MEDIA] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ REBOOT KB│ POWER    │          │          │ VOLUME+  │   │ BRGHTNS+ │ RGB HUE+ │ RGB SAT+ │ RGB BRGH+│ ->MK     │
    QK_RBT   , KC_PWR   , KC_NO    , KC_NO    , KC_VOLU  ,     KC_BRIU  , RGB_HUI  , RGB_SAI  , RGB_VAI  , TMK      ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ BOOT KB  │ SLEEP    │ WIN      │ MAC      │ VOLUME-  │   │ BRGHTNS- │ RGB HUE- │ RGB SAT- │ RGB BRGH-│ ->GAME   │
    QK_BOOT  , KC_SLEP  , TMAINW   , TMAIN    , KC_VOLD  ,     KC_BRID  , RGB_HUD  , RGB_SAD  , RGB_VAD  , TGAME    ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ WAKE     │          │          │ MUTE     │   │RGB ON/OFF│ RGB MODE │          │          │          │
    KC_NO    , KC_WAKE  , KC_NO    , KC_NO    , KC_MUTE  ,     RGB_TOG  , RGB_MOD  , KC_NO    , KC_NO    , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ ->MAIN   │ ->SYS-ARR│   │ ->SYM-NUM│OSM LSHIFT│
         		             TMAIN    , SYSA     ,     SYMN     , OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
    [_MEDIA_WIN] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ REBOOT KB│ POWER    │          │          │ VOLUME+  │   │ BRGHTNS+ │ RGB HUE+ │ RGB SAT+ │ RGB BRGH+│ ->MK     │
    QK_RBT   , KC_PWR   , KC_NO    , KC_NO    , KC_VOLU  ,     KC_BRIU  , RGB_HUI  , RGB_SAI  , RGB_VAI  , TMK      ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ BOOT KB  │ SLEEP    │ WIN      │ MAC      │ VOLUME-  │   │ BRGHTNS- │ RGB HUE- │ RGB SAT- │ RGB BRGH-│ ->GAME   │
    QK_BOOT  , KC_SLEP  , TMAINW   , TMAIN    , KC_VOLD  ,     KC_BRID  , RGB_HUD  , RGB_SAD  , RGB_VAD  , TGAME    ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ WAKE     │          │          │ MUTE     │   │RGB ON/OFF│ RGB MODE │          │          │          │
    KC_NO    , KC_WAKE  , KC_NO    , KC_NO    , KC_MUTE  ,     RGB_TOG  , RGB_MOD  , KC_NO    , KC_NO    , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ ->MAIN   │ ->SYS-ARR│   │ ->SYM-NUM│OSM LSHIFT│
         		             TMAINW   , SYSAW    ,     SYMNW    , OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
    [_SYS_MOU] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│          │          │ MOUSE 1  │ MOUSE 2  │ ESC      │   │ CAPSLOCK │WHEEL LEFT│ MOUSE UP │WHEEL RHGT│ MS ACC 2 │
    KC_NO    , KC_NO    , KC_BTN1  , KC_BTN2  , KC_ESC   ,     KC_CAPS  , KC_WH_L  , KC_MS_U  , KC_WH_R  , KC_ACL2  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ TAB      │ OSM LCTRL│ OSM LALT │ OSM LGUI │ DELETE   │   │ -        │MOUSE LEFT│MOUSE DOWN│MOUSE RGHT│ MS ACC 1 │
    KC_TAB   , OLCTL    , OLALT    , OLGUI    , KC_DEL   ,     KC_PMNS  , KC_MS_L  , KC_MS_D  , KC_MS_R  , KC_ACL1  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │          │          │          │ ENTER    │   │ +        │ WHEEL UP │ ->SYS-ARR│WHEEL DOWN│          │
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_ENT   ,     KC_PPLS  , KC_WH_U  , TSYSA    , KC_WH_D  , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ ->MAIN   │ ->SYS-ARR│   │ ->SYM-NUM│OSM LSHIFT│
         		             TMAIN    , SYSA     ,     SYMN     , OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
    [_SYS_ARR] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ :        │ "        │ MOUSE 1  │ MOUSE 2  │ ESC      │   │ CAPSWORD │ HOME     │ UP       │ END      │ PAGE UP  │
    KC_COLN  , KC_DQT   , KC_BTN1  , KC_BTN2  , KC_ESC   ,     CW_TOGG  , KC_HOME  , KC_UP    , KC_END   , KC_PGUP  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ TAB      │ OSM LCTRL│ OSM LALT │ OSM LGUI │ BACKSPACE│   │ -        │ LEFT     │ DOWN     │ RIGHT    │ PAGE DOWN│
    KC_TAB   , OLCTL    , OLALT    , OLGUI    , KC_BSPC  ,     KC_PMNS  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_PGDN  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ $        │ #        │ @        │ ENTER    │   │ +        │ WHEEL UP │ REPEAT   │WHEEL DOWN│          │
    KC_NO    , KC_DLR   , KC_HASH  , KC_AT    , KC_ENT   ,     KC_PPLS  , KC_WH_U  , QK_REP   , KC_WH_D  , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ ->MAIN   │ ->SYS-ARR│   │ ->SYM-NUM│OSM LSHIFT│
         		             TMAIN    , SYSA     ,     SYMN     ,    OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
    [_SYS_MOU_WIN] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│          │          │ MOUSE 1  │ MOUSE 2  │ ESC      │   │ CAPSLOCK │WHEEL LEFT│ MOUSE UP │WHEEL RHGT│ MS ACC 2 │
    KC_NO    , KC_NO    , KC_BTN1  , KC_BTN2  , KC_ESC   ,     KC_CAPS  , KC_WH_L  , KC_MS_U  , KC_WH_R  , KC_ACL2  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ TAB      │ OSM LGUI │ OSM LALT │ OSM LCTRL│ DELETE   │   │ -        │MOUSE LEFT│MOUSE DOWN│MOUSE RGHT│ MS ACC 1 │
    KC_TAB   , OLGUI    , OLALT    , OLCTL    , KC_DEL   ,     KC_PMNS  , KC_MS_L  , KC_MS_D  , KC_MS_R  , KC_ACL1  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │          │          │          │ ENTER    │   │ +        │ WHEEL UP │ ->SYS-ARR│WHEEL DOWN│          │
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_ENT   ,     KC_PPLS  , KC_WH_U  , TSYSAW   , KC_WH_D  , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ ->MAIN   │ ->SYS-ARR│   │ ->SYM-NUM│OSM LSHIFT│
         		             TMAINW   , SYSAW    ,     SYMNW    , OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
    [_SYS_ARR_WIN] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ :        │ "        │ MOUSE 1  │ MOUSE 2  │ ESC      │   │ CAPSWORD │ HOME     │ UP       │ END      │ PAGE UP  │
    KC_COLN  , KC_DQT   , KC_BTN1  , KC_BTN2  , KC_ESC   ,     CW_TOGG  , KC_HOME  , KC_UP    , KC_END   , KC_PGUP  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ TAB      │ OSM LGUI │ OSM LALT │ OSM LCTRL│ BACKSPACE│   │ -        │ LEFT     │ DOWN     │ RIGHT    │ PAGE DOWN│
    KC_TAB   , OLGUI    , OLALT    , OLCTL    , KC_BSPC  ,     KC_PMNS  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_PGDN  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ $        │ #        │ @        │ ENTER    │   │ +        │ WHEEL UP │ REPEAT   │WHEEL DOWN│          │
    KC_NO    , KC_DLR   , KC_HASH  , KC_AT    , KC_ENT   ,     KC_PPLS  , KC_WH_U  , QK_REP   , KC_WH_D  , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ ->MAIN   │ ->SYS-ARR│   │ ->SYM-NUM│OSM LSHIFT│
         		             TMAINW   , SYSAW    ,     SYMNW    ,    OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
    [_MK] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ Y        │ C        │ L        │ M        │ K        │   │ Z        │ F        │ U        │ Q        │ X        │
    KC_Y     , KC_C     , KC_L     , KC_M     , KC_K     ,     KC_Z     , KC_F     , KC_U     , KC_Q     , KC_X     ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ I        │ S        │ R        │ T        │ G        │   │ P        │ N        │ E        │ A        │ O        │
    KC_I     , KC_S     , KC_R     , KC_T     , KC_G     ,     KC_P     , KC_N     , KC_E     , KC_A     , KC_O     ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ V        │ W        │ D        │ J        │   │ B        │ H        │ ,        │ .        │          │
    KC_NO    , KC_V     , KC_W     , KC_D     , KC_J     ,     KC_B     , KC_H     , KC_COMMA , KC_DOT   , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ MEH & SPC│ ->SYS-ARM│   │ ->SYM-NUM│OSM LSHIFT│
        		             MEHS     , SYSARRMK ,     SYMNW   , OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
    ),
    [_SYS_ARR_MK] = LAYOUT(
//╭──────────┬──────────┬──────────┬──────────┬──────────╮   ╭──────────┬──────────┬──────────┬──────────┬──────────╮
//│ :        │ "        │ MOUSE 1  │ MOUSE 2  │ ESC      │   │ CAPSWORD │ HOME     │ UP       │ END      │ PAGE UP  │
    KC_COLN  , KC_DQT   , KC_BTN1  , KC_BTN2  , KC_ESC   ,     CW_TOGG  , KC_HOME  , KC_UP    , KC_END   , KC_PGUP  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│ TAB      │ OSM LGUI │ OSM LCTRL│ OSM LCTRL│ BACKSPACE│   │ -        │ LEFT     │ DOWN     │ RIGHT    │ PAGE DOWN│
    KC_TAB   , OLGUI    , OLCTL    , OLCTL    , KC_BSPC  ,     KC_PMNS  , KC_LEFT  , KC_DOWN  , KC_RGHT  , KC_PGDN  ,
//├──────────┼──────────┼──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┼──────────┼──────────┤
//│          │ $        │ #        │ @        │ ENTER    │   │ +        │ WHEEL UP │ REPEAT   │WHEEL DOWN│          │
    KC_NO    , KC_DLR   , KC_HASH  , KC_AT    , KC_ENT   ,     KC_PPLS  , KC_WH_U  , QK_REP   , KC_WH_D  , KC_NO    ,
//╰──────────┴──────────┴──────────┼──────────┼──────────┤   ├──────────┼──────────┼──────────┴──────────┴──────────╯
//				   │ ->MK     │ ->SYS-ARR│   │ ->SYM-NUM│OSM LSHIFT│
         		             TMK      , SYSARRMK   ,     SYMNW    ,    OLSFT
//                                 ╰──────────┴──────────╯   ╰──────────┴──────────╯
     ),
  };

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_PURPLE); // sets the color to red without saving
  rgblight_mode_noeeprom(RGBLIGHT_EFFECT_RAINBOW_MOOD + 3); // sets mode to Fast breathing without saving
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 and 1 are left-half encoders
    // 2 and 3 are right-half encoders
    if (index == 0) {
        tap_code(KC_0);
    } else if (index == 1) {
        tap_code(KC_1);
    } else if (index == 2) {
        tap_code(KC_2);
    } else if (index == 3) {
        tap_code(KC_3);
    }

    if (clockwise) {
        tap_code16(KC_PLUS);
    } else {
        tap_code(KC_MINUS);
    }

    return false;
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // A 128x32 OLED rotated 90 degrees is 5 characters wide and 16 characters tall
    // This example string should fill that neatly
    const char *text = PSTR("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789!@#$%^&*()[]{}-=_+?");

    if (is_keyboard_master()) {
        oled_write_P(text, false);
    } else {
        oled_write_P(text, false);
    }
    return false;
}
#endif
