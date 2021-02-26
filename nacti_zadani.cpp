
    void Citani_suboru(string jmeno, mrizka_zadani &Cast_zadani){
      int pocitadlo_i = 0;
      int pocitadlo_k = 0;
      string radek;

      ifstream Soubor;
      Soubor.open(jmeno);

      while (getline(Soubor, radek)){
        pocitadlo_i++;
        pocitadlo_k = 0;

        istringstream is(radek);
        int temporary;
        while( is >> temporary ) {
            pocitadlo_k++;
            Cast_zadani.pixels[pocitadlo_i][pocitadlo_k] = temporary;
        }

        Cast_zadani.pixels[pocitadlo_i][0] = pocitadlo_k;
      }

      Cast_zadani.pixels[0][0] = pocitadlo_i;
      Soubor.close();
    }

void nacitani_zadani_krizovky(string jmeno_bok, string jmeno_vrch){

    Citani_suboru(jmeno_bok, Zadani_bok);
    Citani_suboru(jmeno_vrch, Zadani_vrch);

    pocet_sloupcu_krizovky = Zadani_vrch.pixels[0][0];
    pocet_radku_krizovky = Zadani_bok.pixels[0][0];
}
