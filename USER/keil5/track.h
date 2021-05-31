#ifndef __TRACK_H__
#define __TRACK_H__


#define WHITE 0  //µÆÁÁ
#define BLACK 1  //µÆÃð




void track_init(void);
int get_left_state(void);
int get_right_state(void);
int get_front_state(void);

void track(void);



#endif
