#include <iostream>
#include "clui.h"
using namespace std;
int main(){

    for(int i=1;i<=100;i++){
        cursor_to_pos(get_window_rows() /2 , get_window_cols() /2);
        change_color_rgb(237, 66, 14);
        cout<<i<<endl;
        delay(100);
        clear_screen();
    }
    return 0;
}