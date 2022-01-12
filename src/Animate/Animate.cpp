#include "Animate.h"
#include "config.h"
// #include <TJpg_Decoder.h>

#if Animate_Choice == 1
#include "img/pangzi.h"

int Animate_key = 0; //ͼ����ʾָ���¼

#elif Animate_Choice == 2
#include "img/hutao.h"

int Animate_key = 0; //ͼ����ʾָ���¼
#endif

#if Animate_Choice == 1
//̫�������
void imgAnim(TJpg_Decoder *in_TJpgDec)
{
    TJpgDec = *in_TJpgDec;
    int x = 160, y = 160;
    if (millis() - AprevTime > 41) // x ms�л�һ��
    {
        Animate_key++;
        AprevTime = millis();
    }
    if (Animate_key == 10)
        Animate_key = 0;
    switch (Animate_key)
    {
    case 0:
        TJpgDec.drawJpg(x, y, i0, sizeof(i0));
        break;
    case 1:
        TJpgDec.drawJpg(x, y, i1, sizeof(i1));
        break;
    case 2:
        TJpgDec.drawJpg(x, y, i2, sizeof(i2));
        break;
    case 3:
        TJpgDec.drawJpg(x, y, i3, sizeof(i3));
        break;
    case 4:
        TJpgDec.drawJpg(x, y, i4, sizeof(i4));
        break;
    case 5:
        TJpgDec.drawJpg(x, y, i5, sizeof(i5));
        break;
    case 6:
        TJpgDec.drawJpg(x, y, i6, sizeof(i6));
        break;
    case 7:
        TJpgDec.drawJpg(x, y, i7, sizeof(i7));
        break;
    case 8:
        TJpgDec.drawJpg(x, y, i8, sizeof(i8));
        break;
    case 9:
        TJpgDec.drawJpg(x, y, i9, sizeof(i9));
        break;
    default:
        Serial.println("��ʾAnim����");
        break;
    }
}
#elif Animate_Choice == 2
//����ҡ
// void imgAnim(TJpg_Decoder *in_TJpgDec)
// {
//     TJpgDec = *in_TJpgDec;
//     int x = 160, y = 160;
//     if (millis() - AprevTime > 33) // x ms�л�һ��
//     {
//         Anim++;
//         AprevTime = millis();
//     }
//     if (Anim == 54)
//         Anim = 0;
//     TJpgDec.drawJpg(x, y, hutao[Anim], hutao_size[Anim]);
// }

void imgAnim(const uint8_t **Animate_value, uint32_t *Animate_size)
{

    if (Animate_key < 31)
    {
        Animate_key++;
    }
    else
    {
        Animate_key = 0;
    }
    *Animate_value = hutao[Animate_key];
    *Animate_size = hutao_size[Animate_key];
}
#endif

//�������½�
// void refresh_AnimatedImage(TJpg_Decoder *TJpgDec)
// {
// #if Animate_Choice
//     if (DHT_img_flag == 0)
//         imgAnim(TJpgDec);
// #endif
// }