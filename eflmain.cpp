/*
 * main2.c
 *
 *  Created on: Nov 13, 2012
 *      Author: user
 */

#include <Elementary.h>
#include <iostream>

static void
win_del(void *data, Evas_Object *obj, void *event_info)
{
   elm_exit();
}

 
int main(int argc, char *argv[])
{
   Evas_Object *win, *bg, *lb;

   // Creating window widget
   win = elm_win_add(NULL, "hello", ELM_WIN_BASIC );
   // Adding window title
   elm_win_title_set(win, "Hello");
   // Destructor of window widget
   evas_object_smart_callback_add(win, "delete,request", win_del, NULL);

   // Adding background to window
   bg = elm_bg_add(win);
   // This will be load image as our background
   elm_bg_file_set(bg, "res/backgroung.png", NULL);

   // This will be resize our evas object which is window to setted resolution
   evas_object_resize(win, 400, 640);


   // This is a hint on how a container object should resize a given child within its area
   evas_object_size_hint_weight_set(bg, 1.0, 1.0);
   // You can also use   EVAS_HINT_EXPAND as macro which is define as 1.0 value
   // evas_object_size_hint_weight_set(bg, EVAS_HINT_EXPAND , EVAS_HINT_EXPAND );

   //Thanks to that the child object will be always be formated to parent.
   elm_win_resize_object_add(win, bg);

   // Show evas object
   evas_object_show(bg);

   // Adding lable to window.
   lb = elm_label_add(win);
   // Settimg text which will be displayed on it
   elm_object_text_set(lb, "Hello World!");
   // The same as before, this kind of hint will be helpfull to resize child object
   evas_object_size_hint_weight_set(lb, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   elm_win_resize_object_add(win, lb);

   // And show our Label with text
   evas_object_show(lb);
   // And show our window widget with background and lable with text
   evas_object_show(win);

   // This main loop which will be run for apps
   elm_run();
   // This is main destructor of our apps loop etc
   elm_shutdown();

   // On success our application will return 0
   return 0;
}
ELM_MAIN()
