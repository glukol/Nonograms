
void obraceni_zadani(string zadani_bok, string zadani_vrch, string vystupni_bok, string vystupni_vrch){

    string Otaceni_vrch[rozmery];
    int Otaceni_bok[rozmery];
    int pocitadlo_i;

    ifstream Soubor_bok;
    Soubor_bok.open(zadani_bok);

    ofstream Vystup;
    Vystup.open(vystupni_vrch);

    string radek_bok;
    while (getline(Soubor_bok, radek_bok)){
		pocitadlo_i = 1;

		istringstream is(radek_bok);
		int temporary;
		while( is >> temporary ) {
			Otaceni_bok[pocitadlo_i] = temporary;
			pocitadlo_i++;
		}

		for (int pocitadlo_k = pocitadlo_i - 1; pocitadlo_k >= 2; pocitadlo_k--){
			Vystup << Otaceni_bok[pocitadlo_k];
			Vystup <<  ' ';
		}

		Vystup << Otaceni_bok[1] << "\n";
    }

    Soubor_bok.close();
    Vystup.close();

    ifstream Soubor_vrch;

    Soubor_vrch.open(zadani_vrch);
    Vystup.open(vystupni_bok);

	pocitadlo_i = 0;
    while (getline(Soubor_vrch, Otaceni_vrch[pocitadlo_i])){
      	pocitadlo_i++;
	}

    for (int pocitadlo_k = pocitadlo_i-1; pocitadlo_k >= 0; pocitadlo_k--){
      	Vystup << Otaceni_vrch[pocitadlo_k] << "\n";
	}

    Soubor_vrch.close();
    Vystup.close();
}
