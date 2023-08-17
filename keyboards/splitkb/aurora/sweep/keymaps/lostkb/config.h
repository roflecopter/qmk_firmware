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

#pragma once

#define LED_CAPS_LOCK_PIN 24
#define LED_PIN_ON_STATE 0

#define TAPPING_TERM 300

#define COMBO_TERM 40

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#endif

#define ONESHOT_TAP_TOGGLE 5  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define MOUSEKEY_DELAY            	0	
#define MOUSEKEY_INTERVAL          	32
#define MOUSEKEY_MOVE_DELTA		8
#define MOUSEKEY_MAX_SPEED         	5
#define MOUSEKEY_TIME_TO_MAX       	60
#define MOUSEKEY_WHEEL_DELAY		0
#define MOUSEKEY_WHEEL_INTERVAL		103
#define MOUSEKEY_WHEEL_MAX_SPEED   	8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 	45

