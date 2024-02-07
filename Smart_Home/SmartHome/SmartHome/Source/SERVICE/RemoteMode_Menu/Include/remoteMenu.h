/*
 * remoteMenu.h
 *
 * Created: 2/6/2024 9:44:09 PM
 *  Author: ali_e
 */ 


#ifndef REMOTEMENU_H_
#define REMOTEMENU_H_

#define REMOTE_MENU		(3)
#define LED_MENU		(0)
#define AC_MENU			(1)

#define AC_ON_OFF		(0)
#define AC_RUN_TEMP		(1)
#define AC_STOP_TEMP	(2)
#define AC_RETURN		(3)

void remote_menu_Service(void);

#endif /* REMOTEMENU_H_ */