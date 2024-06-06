#include QMK_KEYBOARD_H

enum layer_names {
    _CMK,
    _NUM,
    _NAV,
    _FUN,
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_CMK] = LAYOUT_split_3x5_2(
            //left row 1
	        KC_Q, KC_W, KC_F, KC_P, LT(_FUN, KC_B),    
                        //right row 1    
                        LT(_FUN, KC_J), KC_L, KC_U, KC_Y, KC_SCLN,
			//left row 2
            KC_A, KC_R, KC_S, KC_T, KC_G,    
                        //right row 2
                        KC_K, KC_N, KC_E, KC_I, KC_O,
            //left row 3    
            XXXXXXX, LALT_T(KC_X), LGUI_T(KC_C), LCTL(KC_D), KC_V,    
                        //right row 3
                        RCTL_T(KC_M), RGUI(KC_H), RALT(KC_COMM), KC_DOT, KC_SLSH,

            //left thumb
		    LSFT_T(KC_BSPC), LT(_NAV, KC_TAB),    
                        //right thumb
                        LT(_NUM, KC_ENT), RSFT_T(KC_SPC)
							   ),

	[_NUM] = LAYOUT_split_3x5_2(
            //left row 1
			KC_1, KC_2, KC_3, KC_4, KC_5,   
                        //right row 1
                        KC_BSPSC, RSFT(KC_TAB), KC_ENT,KC_TAB, KC_DEL,
			//left row 2
            KC_6, KC_7, KC_8, KC_9, KC_0,    
                        //right row 2
                        KC_DOT,  KC_PLUS, KC_MINUS, KC_ASTERISK, KC_SLASH,
            //left row 3
            _______, LALT_T(KC_LEFT), LGUI_T(KC_UP), LCTL(KC_EQUAL), KC_UNDS,   
                        //right row 3
                        KC_CIRC, KC_RCTL, RGUI_T(KC_DOWN), RALT_T(KC_RIGHT), KC_BACKSLASH,

            //left thumb
			_______, TO(_CMK),
                        //right thumb
                        XXXXXXX, _______ 
								),

	[_NAV] = LAYOUT_split_3x5_2(
            //left row 1				
            LCTL_T(KC_LBRC), LSFT_T(KC_RBRC),KC_LT, KC_GT,KC_HOME,
                        //right row 1				
                        KC_END, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
            //left row 2				
            KC_LALT, KC_LGUI, KC_BSPC, KC_SPC, KC_TAB,
                        //right row 2				
                        KC_LEFT, KC_DOWN, KC_UP,KC_RGHT,KC_ENT,
            //left row 3				
            TO(_FUN), XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
                        //right row 3				
                        XXXXXXX, XXXXXXX, XXXXXX,XXXXXXX, XXXXXXX,
            //left thumb				
            _______, TO(0),	
                        //right thumb
                       XXXXXXX XXXXXXX, _______
							   ),

	[_FUN] = LAYOUT_split_3x5_2(
            //left row 1				
            KC_F1, KC_F2, KC_F3, KC_F4, TO(_NAV),
                        //right row 1				
                        TO(_NUM), KC_VOLU, KC_VOLD, KC_MUTE, KC_MPLY,
            //left row 2				
            KC_F5, KC_F6, KC_F7, KC_8, KC_CPNL,
                        //right row 2				
                        KC_MPRV, KC_MNXT, KC_ASST,KC_PWR,KC_RGUI,
            //left row 3				
            KC_F9, KC_F10, KC_F11, KC_F12,XXXXXXX, 
                        //right row 3				
                        QK_BOOT, QK_REBOOT, QK_CLEAR_EEPROM, QK_MAKE, KC_RCTL,
            //left thumb				
            KC_LALT, TO(0),	
                        //right thumb
                        XXXXXXX, KC_RALT
								),


};


enum combo_events {
//HORIZONTAL
//qw=grv_esc
GRAVE_ESC_COMBO,
//wfp=mouse right 1
MOUSE_1_COMBO,
//fp=mouse left click 2
MOUSE_2_COMBO,
//qwfp=mouse center click 3
MOUSE_3_COMBO,
//wf=caps lock
CAPS_LOCK_COMBO,
//st=select left (ctrl shift left)
//tg=select right (ctl sft right)
//rt=redo(ctl y)
//dv=undo(ctl z)
//ar=z(bunk slot bottom left)
//io=delete
//nei=equal sign
//lu=&
//uy=|
//kn=!
//mh=@
//ne=double quote
//ei=single quote
//luy;=scroll up
//neio=scroll down
//wf=caps lock
//rs=CW_TOGG
//
//VERTICAL
//fs=select all(ctl a)
//pt=cut
//td=copy
//gv=paste
//nh=_
//ln=# 
//ue=$
//yi=%
//wr=ctrl f
//
//SPLIT
//
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
//HORIZONTAL
//qw=grv_esc
const uint16_t PROGMEM grv_esc_combo[] = {KC_G, KC_W, COMBO_END};
//wfp=mouse right 1
const uint16_t PROGMEM mouse_1_combo[] = {KC_W, KC_F, KC_P, COMBO_END};
//fp=mouse left click 2
const uint16_t PROGMEM mouse_2_combo[] = {KC_F, KC_P, COMBO_END};
//qwfp=mouse center click 3
const uint16_t PROGMEM mouse_3_combo[] = {KC_Q,KC_W,KC_F, KC_P, COMBO_END};
//wf=caps lock
const uint16_t PROGMEM caps_log_combo[] = {KC_W,KC_F, COMBO_END};
//st=select left (ctrl shift left)
const uint16_t PROGMEM left_select_combo[] = {KC_S,KC_T, COMBO_END};
//tg=select right (ctl sft right)
const uint16_t PROGMEM right_select_combo[] = {KC_T,KC_G, COMBO_END};
//rt=redo(ctl y)
const uint16_t PROGMEM redo_combo[] = {KC_R,KC_T, COMBO_END};
//dv=undo(ctl z)
const uint16_t PROGMEM undo_combo[] = {KC_D,KC_V, COMBO_END};
//ar=z(bunk slot bottom left)
const uint16_t PROGMEM zed_combo[] = {KC_A,KC_R, COMBO_END};
//io=delete
const uint16_t PROGMEM delete_combo[] = {KC_I,KC_O, COMBO_END};
//nei=equal sign
const uint16_t PROGMEM equals_combo[] = {KC_N,KC_E,KC_I,COMBO_END};
//lu=&
const uint16_t PROGMEM ampersand_combo[] = {KC_L,KC_U,COMBO_END};
//uy=|
const uint16_t PROGMEM pipe_combo[] = {KC_U, KC_Y, COMBO_END};
//kn=!
const uint16_t PROGMEM bang_combo[] = {KC_K, KC_N, COMBO_END};
//mh=@
const uint16_t PROGMEM at_combo[] = {KC_M, KC_H, COMBO_END};
//ne=double quote
const uint16_t PROGMEM double_quote_combo[] = {KC_N, KC_E, COMBO_END};
//ei=single quote
const uint16_t PROGMEM single_quote_combo[] = {KC_E, KC_I, COMBO_END};
//luy;=scroll up
const uint16_t PROGMEM ms_scroll_up_combo[] = {KC_L,KC_U, KC_Y,KC_SCLN,COMBO_END};
//neio=scroll down
const uint16_t PROGMEM ms_scroll_down_combo[] = {KC_N,KC_E, KC_I,KC_O,COMBO_END};
//rs=CW_TOGG
const uint16_t PROGMEM caps_word_toggle_combo[] = {KC_R,KC_S,COMBO_END};
//VERTICAL
//fs=select all(ctl a)
const uint16_t PROGMEM select_all_combo[] = {KC_F,KC_S,COMBO_END};
//pt=cut
const uint16_t PROGMEM cut_combo[] = {KC_P,KC_T,COMBO_END};
//td=copy
const uint16_t PROGMEM copy_combo[] = {KC_T,KC_D,COMBO_END};
//gv=paste
const uint16_t PROGMEM paste_combo[] = {KC_G,KC_V,COMBO_END};
//nh=_
const uint16_t PROGMEM underscore_combo[] = {KC_N,KC_H,COMBO_END};
//ln=# 
const uint16_t PROGMEM hashtag_combo[] = {KC_L,KC_N,COMBO_END};
//ue=$
const uint16_t PROGMEM dollar_combo[] = {KC_U,KC_E,COMBO_END};
//yi=%
const uint16_t PROGMEM percent_combo[] = {KC_Y,KC_I,COMBO_END};
//wr=ctrl f
const uint16_t PROGMEM find_combo[] = {KC_W,KC_R,COMBO_END};
//
//SPLIT
//




combo_t key_combos[] = {
//HORIZONTAL
//qw=grv_esc
//wfp=mouse right 1
//fp=mouse left click 2
//qwfp=mouse center click 3
//wf=caps lock
//st=select left (ctrl shift left)
//tg=select right (ctl sft right)
//rt=redo(ctl y)
//dv=undo(ctl z)
//ar=z(bunk slot bottom left)
//io=delete
//nei=equal sign
//lu=&
//uy=|
//kn=!
//mh=@
//ne=double quote
//ei=single quote
//luy;=scroll up
//neio=scroll down
//wf=caps lock
//rs=CW_TOGG
//
//VERTICAL
//fs=select all(ctl a)
//pt=cut
//td=copy
//gv=paste
//nh=_
//ln=# 
//ue=$
//yi=%
//wr=ctrl f
//
//SPLIT
//
  [CAPS_COMBO_Q] = COMBO_ACTION(caps_combo_q),
  [ENTER_COMBO_Q] = COMBO(enter_combo_q, KC_ENT),
  [TAB_COMBO_Q] = COMBO(tab_combo_q, KC_TAB),
  [BSP_COMBO_Q] = COMBO(bsp_combo_q, KC_BSPC),
  [DEL_COMBO_Q] = COMBO(del_combo_q, KC_DEL),
  [CTRLC_COMBO_Q] = COMBO(ctrlc_combo_q, LCTL(KC_C)),
  [ESC_COMBO_Q] = COMBO(esc_combo_q, KC_ESC),
  [LCBR_COMBO_Q] = COMBO(lcbr_combo_q, KC_LCBR),
  [LPRN_COMBO_Q] = COMBO(lprn_combo_q, KC_LPRN),
  [LBRC_COMBO_Q] = COMBO(lbrc_combo_q, KC_LBRC),
  [RCBR_COMBO_Q] = COMBO(rcbr_combo_q, KC_RCBR),
  [RPRN_COMBO_Q] = COMBO(rprn_combo_q, KC_RPRN),
  [RBRC_COMBO_Q] = COMBO(rbrc_combo_q, KC_RBRC),
  // alternative braces
  [LCBR_COMBO_Q2] = COMBO(lcbr_combo_q2, KC_LCBR),
  [LPRN_COMBO_Q2] = COMBO(lprn_combo_q2, KC_LPRN),
  [RCBR_COMBO_Q2] = COMBO(rcbr_combo_q2, KC_RCBR),
  [RPRN_COMBO_Q2] = COMBO(rprn_combo_q2, KC_RPRN),
  // toggle utility layer
  [UTIL_COMBO_Q]  = COMBO(util_combo_q, TG(_UTIL)),
  [UTIL_COMBO_Q2]  = COMBO(util_combo_q2, TG(_UTIL)),
  [UTIL_COMBO_Q3]  = COMBO(util_combo_q3, TG(_UTIL)),
  // toggle game layer
  [UTIL_COMBO_Q]  = COMBO(game_combo_q, TG(_GAME)),
  [UTIL_COMBO_Q2]  = COMBO(game_combo_q2, TG(_GAME)),
  // game layer combos
  [ENTER_COMBO_G] = COMBO(enter_combo_g, KC_ENT),

  // rshift
  [RSFT_COMBO_Q]  = COMBO_ACTION(rsft_combo_q),

};


