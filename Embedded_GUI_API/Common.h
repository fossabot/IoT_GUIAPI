#pragma once

/******************** Enums ***********************************************/
typedef enum
{
	GUI_RESULT_SUCCESSFUL = 0,     /*OK*/
	GUI_RESULT_ERROR = -1001, /*Ошибка*/
	GUI_RESULT_OUT_OF_MEMORY = -1002, /*Нехватака памяти*/
}
EGUIResult;

typedef enum
{
	GUI_CALLBACK_RESULT_SUCCESSFUL = 0,	/*OK*/
	GUI_CALLBACK_RESULT_ERROR = -1001,/*Ошибка*/

}EGUICallbackResult;

/********************* Callbacks *****************************************/
typedef EGUICallbackResult(*FnDrawPixel)();
typedef EGUICallbackResult(*FnClearScreen)();


/******************** Struct **********************************************/
typedef struct SGUI_Callbacks_
{
	FnDrawPixel   fnDrawPixel;
	FnClearScreen fFnClearScreen;
}SGUI_Callbacks;
