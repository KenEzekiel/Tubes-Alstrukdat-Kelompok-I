#include "process.h"
#include "../utility/utility.h"
#include "../waktusim/mekawaktu.h"


void buyMechanism(State *S, ListMakanan LM, stackaddr US, Notif *listNotif)
{
    String aksiBuy, foodName;
    ListMakanan listBuy;
    int opt, idx, idFood;

    charToString("BUY", &aksiBuy, 3);
    displayFilteredAksi(aksiBuy, LM, &listBuy);
    print_red("\nKirim 0 untuk exit\n");

    print_blue("Masukkan pilihan: ");
    STARTWORD();
    while (!isInt(currentWord))
    {
        print_red("Input yang dimasukkan tidak valid.\n");
        print_blue("Masukkan pilihan: ");
        STARTWORD();
    }
    opt = WordToInt(currentWord);

    while (opt != 0)
    {
        idFood = ID(ELMT_LM(listBuy, opt - 1));
        idx = indexOfID(listBuy, idFood);
        if (idx == IDX_UNDEF_LMAKANAN)
        {
            printf("Makanan yang dipilih tidak valid. Silahkan input kembali.\n");
        }
        else
        {
            foodName = Nama(ELMT_LM(listBuy, idx));
            PushUndoStack(US, *S);
            initializeNotif(S);
            buyMakananbyId(&DeliveryListState(*S), idFood, listBuy);
            UpdateActionTime(S);
            updateNotif(S, listNotif);
            printf("Berhasil memesan "); displayString(foodName); printf(". ");
            displayString(foodName); printf(" akan diantar dalam "); PrintTime(DelivTime(ELMT_LM(listBuy, idx))); printf(".\n");
        }
        print_blue("Masukkan pilihan: ");
        STARTWORD();
        while (!isInt(currentWord))
        {
            print_red("Input yang dimasukkan tidak valid.\n");
            print_blue("Masukkan pilihan: ");
            STARTWORD();
        }
        opt = WordToInt(currentWord);
    }
}

void olahMechanism(String aksi, State *S, ListMakanan LM, ResepTree Resep,stackaddr US, Notif *listNotif)
{
    String foodName;
    ListMakanan listAksi;
    int opt, idx, idFood;

    displayFilteredAksi(aksi, LM, &listAksi);
    print_red("\nKirim 0 untuk exit\n");

    print_blue("Masukkan pilihan: ");
    STARTWORD();
    while (!isInt(currentWord))
    {
        print_red("Input yang dimasukkan tidak valid.\n");
        print_blue("Masukkan pilihan: ");
        STARTWORD();
    }
    opt = WordToInt(currentWord);

    while (opt != 0)
    {
        idFood = ID(ELMT_LM(listAksi, opt - 1));
        idx = indexOfID(listAksi, idFood);

        if (idx == IDX_UNDEF_LMAKANAN)
        {
            printf("Makanan yang dipilih tidak valid. Silahkan input kembali.\n");
        }
        else
        {
            foodName = Nama(ELMT_LM(listAksi, idx));
            ListMakanan lneeded; CreateListMakanan(&lneeded);
            lneeded = listNeeded(idFood, Resep, LM);

            if (!isAvailable(InventoryState(*S), lneeded))
            {
                printf("Gagal membuat ");
                displayString(foodName);
                printf(" karena kamu tidak memiliki bahan berikut:\n ");
                int count = 1;
                for (int i = 0; i < listMakananLength(lneeded); i++)
                {
                    if (!isElmtById(InventoryState(*S), ID(ELMT_LM(lneeded, i))))
                    {
                        printf("%d. ", count);
                        displayString(Nama(ELMT_LM(lneeded,i)));
                        printf("\n");
                        count++;
                    }
                }
            }
            else
            {
                PushUndoStack(US, *S);
                initializeNotif(S);
                process(idFood, &InventoryState(*S), lneeded, listAksi, &ProcessedList(*S));
                UpdateActionTime(S);
                updateNotif(S, listNotif);
            }
            print_blue("Masukkan pilihan: ");
            STARTWORD();
            while (!isInt(currentWord))
            {
                print_red("Input yang dimasukkan tidak valid.\n");
                print_blue("Masukkan pilihan: ");
                STARTWORD();
            }
            opt = WordToInt(currentWord);
        }
    }
}