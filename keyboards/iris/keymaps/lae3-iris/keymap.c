#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum iris_layers {
    _QWERTY,
    _ARROW,
    _SWAP,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
};

enum tap_dance_codes {
    TD_LSFT_LCTL = 0,
    TD_RSFT_RCTL,
    TD_LGUI_LALT,
    TD_RGUI_RALT
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_LCTL] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_LCTL),
    [TD_RSFT_RCTL] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_RCTL),
    [TD_LGUI_LALT] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LALT),
    [TD_RGUI_RALT] = ACTION_TAP_DANCE_DOUBLE(KC_RGUI, KC_RALT)
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET

#define KC_TG_A TG(_ARROW)
#define KC_TG_S TG(_SWAP)

#define KC_TDLS TD(TD_LSFT_LCTL)
#define KC_TDRS TD(TD_RSFT_RCTL)
#define KC_TDLG TD(TD_LGUI_LALT)
#define KC_TDRG TD(TD_RGUI_RALT)

#define KC_CTLZ LCTL(KC_Z)
#define KC_CTLX LCTL(KC_X)
#define KC_CTLC LCTL(KC_C)
#define KC_CTLV LCTL(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_kc(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,CAPS,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       BSPC, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
    //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
       TDLS, Z  , X  , C  , V  , B  ,LBRC,     RBRC, N  , M  ,COMM,DOT ,SLSH,TDRS,
    //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                         TDLG,LOWR,ENT ,         SPC ,RASE,TDRG
    //                  `----+----+----'        `----+----+----'
    ),

    [_ARROW] = LAYOUT_kc(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
           ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,                   ,    ,    ,    , UP ,    ,
    //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,LEFT,DOWN,RGHT,
    //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                             ,    ,    ,             ,    ,
    //                  `----+----+----'        `----+----+----'
    ),

    [_SWAP] = LAYOUT_kc(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
           ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
    //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                             ,    ,SPC ,         ENT ,    ,
    //                  `----+----+----'        `----+----+----'
    ),

    [_LOWER] = LAYOUT_kc(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
           ,TILD,GRV ,SLCK,PAUS,PSCR,               EQL ,MINS,PLUS,UNDS,INS ,    ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,               LEFT,DOWN, UP ,RGHT,DEL ,    ,
    //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,    ,         ,HOME,PGDN,PGUP,END ,    ,    ,
    //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                             ,    ,    ,             ,    ,
    //                  `----+----+----'        `----+----+----'
    ),

    [_RAISE] = LAYOUT_kc(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
           ,NLCK, P7 , P8 , P9 ,PSLS,                   ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
           ,PENT, P4 , P5 , P6 ,PAST,                   ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
           ,    , P1 , P2 , P3 ,PMNS,                   ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
           ,    ,    , P0 ,PDOT,PPLS,    ,         ,    ,    ,    ,    ,    ,    ,
    //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                             ,    ,    ,             ,    ,
    //                  `----+----+----'        `----+----+----'
    ),

    [_ADJUST] = LAYOUT_kc(
    //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
       RST ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
       PWR ,    ,MSTP,MPLY,VOLU,    ,                   ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----|              |----+----+----+----+----+----|
           ,    ,MPRV,MNXT,VOLD,MUTE,                   ,TG_A,TG_S,    ,    ,    ,
    //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
    //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                             ,    ,    ,             ,    ,
    //                  `----+----+----'        `----+----+----'
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
            return false;
            break;
    }
    return true;
}
