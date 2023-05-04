#ifndef SEGMENTDISPLAY_H_INCLUDED
#define SEGMENTDISPLAY_H_INCLUDED

#include <windows.h>

#define LED_LENGTH 50
#define LED_THICK 14
#define LED_X 30
#define LED_Y 40
#define LED_SPACE 3

int disp_num = 0;
extern int seg_disp_num;

HWND hwndLEDs[10][7];
//HWND hwndLEDs2[7];
int disp_pin_start[10];

HBITMAP onVertImg = (HBITMAP) LoadImageW(NULL, L"Images\\verticalOn.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
HBITMAP offVertImg = (HBITMAP) LoadImageW(NULL, L"Images\\verticalOff.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
HBITMAP onHorImg = (HBITMAP) LoadImageW(NULL, L"Images\\horisontalOn.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
HBITMAP offHorImg = (HBITMAP) LoadImageW(NULL, L"Images\\horisontalOff.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);


char* classNames[10] = {"SegmentDisplayWindowClass1",
                        "SegmentDisplayWindowClass2",
                        "SegmentDisplayWindowClass3",
                        "SegmentDisplayWindowClass4",
                        "SegmentDisplayWindowClass5",
                        "SegmentDisplayWindowClass6",
                        "SegmentDisplayWindowClass7",
                        "SegmentDisplayWindowClass8",
                        "SegmentDisplayWindowClass9",
                        "SegmentDisplayWindowClass10"};

DWORD WINAPI childDisplayLoop(LPVOID lpParam){

    int startPin;
    int number;
    while(1){
        for(int j = 0; j < seg_disp_num; j++){
            startPin = disp_pin_start[j];
            number = digitalRead(startPin+3)<<3 | digitalRead(startPin+2)<<2 | digitalRead(startPin+1)<<1 | digitalRead(startPin);
            switch(number){
            case 0:
                for(int i = 0; i < 4; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                }
                for(int i = 4; i < 7; i++){
                    if(i != 5){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offHorImg);
                    }

                }
                break;
            case 1:
                for(int i = 0; i < 4; i++){
                    if(i == 2 | i == 3){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }

                }
                for(int i = 4; i < 7; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offHorImg);
                }
                break;
            case 2:
                for(int i = 0; i < 4; i++){
                    if(i == 2 | i == 1){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }
                }
                for(int i = 4; i < 7; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                }
                break;
            case 3:
                for(int i = 0; i < 4; i++){
                    if(i == 2 | i == 3){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }
                }
                for(int i = 4; i < 7; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                }
                break;
            case 4:
                for(int i = 0; i < 4; i++){
                    if(i == 0 | i == 2 | i == 3 ){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }

                }
                for(int i = 4; i < 7; i++){
                    if(i == 5){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offHorImg);
                    }
                }
                break;
            case 5:
                for(int i = 0; i < 4; i++){
                    if(i == 0 | i == 3 ){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }

                }
                for(int i = 4; i < 7; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                }
                break;
            case 6:
                for(int i = 0; i < 4; i++){
                    if(i != 2){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }

                }
                for(int i = 4; i < 7; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                }
                break;
            case 7:
                for(int i = 0; i < 4; i++){
                    if(i == 2 | i == 3){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }

                }
                for(int i = 4; i < 7; i++){
                    if(i == 4){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offHorImg);
                    }
                }
                break;
            case 8:
                for(int i = 0; i < 4; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                }
                for(int i = 4; i < 7; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                }
                break;
            case 9:
                for(int i = 0; i < 4; i++){
                    if(i == 1){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }

                }
                for(int i = 4; i < 7; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                }
                break;
            case 10:
                for(int i = 0; i < 4; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                }
                for(int i = 4; i < 7; i++){
                    if(i == 6){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offHorImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                    }
                }
                break;
            case 11:
                for(int i = 0; i < 4; i++){
                    if(i == 2){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }
                }
                for(int i = 4; i < 7; i++){
                    if(i == 4){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offHorImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                    }
                }
                break;
            case 12:
                for(int i = 0; i < 4; i++){
                    if(i == 3 | i == 2){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }
                }
                for(int i = 4; i < 7; i++){
                    if(i == 5){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offHorImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                    }
                }
                break;
            case 13:
                for(int i = 0; i < 4; i++){
                    if(i == 0 ){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }
                }
                for(int i = 4; i < 7; i++){
                    if(i == 4){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offHorImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                    }
                }
                break;
            case 14:
                for(int i = 0; i < 4; i++){
                    if(i == 2 | i == 3){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }
                }
                for(int i = 4; i < 7; i++){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);            }
                break;
            case 15:
                for(int i = 0; i < 4; i++){
                    if(i == 2 | i == 3){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
                    }
                }
                for(int i = 4; i < 7; i++){
                    if(i == 6){
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offHorImg);
                    }else{
                        SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onHorImg);
                    }
                }
                break;
            default:
                for(int i = 0; i < 4; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);
                }
                for(int i = 4; i < 7; i++){
                    SendMessageW(hwndLEDs[j][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offHorImg);
                }
                break;
            }
            //SendMessageW(hwndLEDs[j][3],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
            //SendMessageW(hwndLEDs[j][3],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offVertImg);

        }
    }
}

int WINAPI createDisplayWnd(HWND* retVal){
    HWND parentWnd = FindWindowA("ArduinoWindowClass",NULL);
    if(parentWnd == NULL){
        return 1;
    }

    HWND hwnd;
    MSG msg;
    WNDCLASSEX wc = {0};
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = DefWindowProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = NULL;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = classNames[disp_num];
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
               WS_EX_CLIENTEDGE,
               classNames[disp_num],
               "7SD",
               (WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME) | WS_EX_CONTROLPARENT,
               CW_USEDEFAULT, CW_USEDEFAULT, 155, 200,
               NULL, NULL,NULL, NULL);
    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }
    ShowWindow(hwnd, 0);
    UpdateWindow(hwnd);
    *retVal = hwnd;
    //adding stuff to it
    CreateWindow(TEXT("static"), TEXT("OUTPUT: "), WS_VISIBLE | WS_CHILD,
                                         5, 5, 70, 20, hwnd, (HMENU) 100, NULL, NULL);


    hwndLEDs[disp_num][0] = CreateWindow(TEXT("static"),NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP | SS_NOTIFY,
                                                        LED_X,LED_Y,100,100,hwnd,(HMENU)-1,NULL,NULL);
    hwndLEDs[disp_num][1] = CreateWindow(TEXT("static"),NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP | SS_NOTIFY,
                                                        LED_X,LED_Y + LED_SPACE + LED_LENGTH,100,100,hwnd,(HMENU)-1,NULL,NULL);
    hwndLEDs[disp_num][2] = CreateWindow(TEXT("static"),NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP | SS_NOTIFY,
                                                        LED_X + 2*LED_SPACE + LED_LENGTH + LED_THICK,LED_Y,100,100,hwnd,(HMENU)-1,NULL,NULL);
    hwndLEDs[disp_num][3] = CreateWindow(TEXT("static"),NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP | SS_NOTIFY,
                                                        LED_X + 2*LED_SPACE + LED_LENGTH + LED_THICK,LED_Y + LED_SPACE + LED_LENGTH,100,100,hwnd,(HMENU)-1,NULL,NULL);
    hwndLEDs[disp_num][4] = CreateWindow(TEXT("static"),NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP | SS_NOTIFY,
                                                        LED_X + LED_THICK + LED_SPACE,LED_Y -(LED_THICK/2),100,100,hwnd,(HMENU)-1,NULL,NULL);
    hwndLEDs[disp_num][5] = CreateWindow(TEXT("static"),NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP | SS_NOTIFY,
                                                        LED_X + LED_THICK + LED_SPACE,LED_Y -(LED_THICK/2) + LED_LENGTH + LED_SPACE,100,100,hwnd,(HMENU)-1,NULL,NULL);
    hwndLEDs[disp_num][6] = CreateWindow(TEXT("static"),NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP | SS_NOTIFY,
                                                        LED_X + LED_THICK + LED_SPACE,LED_Y -(LED_THICK/2) + 2*LED_LENGTH + 2*LED_SPACE,100,100,hwnd,(HMENU)-1,NULL,NULL);

    for(int i = 0; i < 4; i++){
        SendMessageW(hwndLEDs[disp_num][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)onVertImg);
    }
    for(int i = 4; i < 7; i++){
        SendMessageW(hwndLEDs[disp_num][i],STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)offHorImg);
    }

    //     Step 3: The  Loop
    disp_num++;
    if(disp_num == 1){
        DWORD threadId;
        HANDLE threadHandle = CreateThread(NULL,0,&childDisplayLoop,NULL,0,&threadId);
        CloseHandle(threadHandle);
    }
    return msg.wParam;
}



#endif // SEGMENTDISPLAY_H_INCLUDED
