combo_dict = {}
with open('combos.def', 'r') as file:
    for line in file:
        
        #remove the last character in all lines
        line = line[:-1]
        
        parts = line.split(',')
        parts[-1] = parts[-1][:-1]
        name = parts[0].split('combo_')[1]
        combo_keys = parts[2:]
        for i in range(len(combo_keys)):
            combo_keys[i] = combo_keys[i].strip()
            # if combo_keys[i][-1] == ')':
            #     combo_keys[i] = combo_keys[i][:-1]
        combo_dict[name] = combo_keys
        
# print(combo_dict)
basemap =    "KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,CTL_T(KC_A),KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,CTL_T(KC_SCLN),SFT_T(KC_Z),ALT_T(KC_X),KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMMA,KC_DOT,SFT_T(KC_SLSH),OSM(MOD_LSFT),OSL(1),LT(2,KC_SPC),OSL(3)".split(',')
for key in combo_dict:
    for i in range(len(combo_dict[key])):
        if combo_dict[key][i] in basemap:
            combo_dict[key][i] = basemap.index(combo_dict[key][i])

string = ''
with open('combos.txt', 'w') as file:
    for key in combo_dict:
        string += '  - {p: ' + str(combo_dict[key]) + ', k: ' + key + ', l: ["L0"]}\n'

    file.write(string)