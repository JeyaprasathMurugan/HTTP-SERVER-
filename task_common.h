/*
 * task_common.h
 *
 *  Created on: 11 May 2024
 *      Author: jeyap
 */

#ifndef MAIN_TASK_COMMON_H_
#define MAIN_TASK_COMMON_H_

#define TASK_SIZE 4096
#define TASK_PRIORITY 5
#define TASK_CORE 0

// HTTP Server task
#define HTTP_SERVER_TASK_STACK_SIZE			8192
#define HTTP_SERVER_TASK_PRIORITY			4
#define HTTP_SERVER_TASK_CORE_ID			0

// HTTP Server Monitor task
#define HTTP_SERVER_MONITOR_STACK_SIZE		4096
#define HTTP_SERVER_MONITOR_PRIORITY		3
#define HTTP_SERVER_MONITOR_CORE_ID			0


#endif /* MAIN_TASK_COMMON_H_ */
