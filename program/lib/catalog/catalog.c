void DisplayCatalog(ListMakanan* Makanan)
/*  Menampilkan catalog pada layar (berisi nama, waktu kadaluwarsa
	aksi, dan waktu pengiriman
	I.S. : Makanan terdefinisi
	F.S. : Catalog tercetak pada layar */
{
	printf("List Makanan\n");

	for (int i = 0; i < LENGTH(*Makanan); i++)
	{
		displayString(Nama(ELMT_LM(*Makanan,i))); printf("\t-");
		TulisTime(Exp(ELMT_LM(*Makanan,i))); printf("\t-");
		displayString(Aksi(ELMT_LM(*Makanan,i))); printf("\t-");
		TulisTime(DelivTime(ELMT_LM(*Makanan,i))); printf("\n");
	}
}