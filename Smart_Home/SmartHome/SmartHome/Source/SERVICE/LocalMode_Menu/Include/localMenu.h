#ifndef LOCALMENU_H_
#define LOCALMENU_H_

#define LOCAL_MENU		(3)
#define LED_MENU		(0)
#define AC_MENU			(1)

#define MOVE_UP			(0)
#define MOVE_DOWN		(1)

#define AC_ON_OFF		(0)
#define AC_RUN_TEMP		(1)
#define AC_STOP_TEMP	(2)
#define AC_RETURN		(3)

void local_menu_init(void);

void local_menu_Service(void);

void local_menu_Idle_Reset(void);
#endif /* LOCALMENU_H_ */