      void posun(int radek, int sloupec){
        //{sme_v_krizovce: boolean;
        //sme_o_radek_dal: boolean;
        //nevymalovane: boolean;
        //predesli_nevymalovany: boolean;   }

        int kolko_jeste_precuhuje;
        int kde_je_posledni_vypoustena_mezera;
        int jake_misto_v_sloupci_kontrolujeme;
        //pocitadlo_i: integer;

        //{sme_v_krizovce := radek < pocet_radku_krizovky;
        //sme_o_radek_dal := radek - 1 = pocet_radku_krizovky;
        //nevymalovane := krizovka[radek, sloupec] <> vybarvene;
        //predesli_nevymalovany := krizovka[radek + 1, sloupec] <> vybarvene;

        //if not (nevymalovane and (sme_o_radek_dal or
        //  (predesli_nevymalovany and sme_v_krizovce))) then
        //  posun(radek + 1, sloupec);

        //if radek <> pocet_radku_krizovky then
        //  krizovka[radek + 1, sloupec] := krizovka[radek, sloupec];       }

        kolko_jeste_precuhuje = -radek;
        jake_misto_v_sloupci_kontrolujeme = radek;

        while ((kolko_jeste_precuhuje >= 0) && (jake_misto_v_sloupci_kontrolujeme <= pocet_radku_krizovky)){

          if ((jake_misto_v_sloupci_kontrolujeme == pocet_radku_krizovky) && (Krizovka.pixels[jake_misto_v_sloupci_kontrolujeme + rozmery][sloupec] != vybarvene)){
            kolko_jeste_precuhuje--;
            kde_je_posledni_vypoustena_mezera = jake_misto_v_sloupci_kontrolujeme;
          }
          else
          if ((Krizovka.pixels[jake_misto_v_sloupci_kontrolujeme + rozmery][sloupec] != vybarvene) && (Krizovka.pixels[jake_misto_v_sloupci_kontrolujeme + 1 + rozmery][sloupec] != vybarvene)){
            kolko_jeste_precuhuje--;
            kde_je_posledni_vypoustena_mezera = jake_misto_v_sloupci_kontrolujeme;
          }
          jake_misto_v_sloupci_kontrolujeme++;
        }


        if (kolko_jeste_precuhuje >= 0){
          cout << "Zadani se nevejde do krizovky!" << '\n';
        }
        else{
          int pocitadlo_i = kde_je_posledni_vypoustena_mezera;
          jake_misto_v_sloupci_kontrolujeme = kde_je_posledni_vypoustena_mezera;
          while (pocitadlo_i >= radek){
            if (Krizovka.pixels[pocitadlo_i + rozmery][sloupec] == vybarvene){
              if (Krizovka.pixels[pocitadlo_i - 1 + rozmery][sloupec] == vybarvene){
                Krizovka.pixels[jake_misto_v_sloupci_kontrolujeme + rozmery][sloupec] = vybarvene;
                jake_misto_v_sloupci_kontrolujeme--;
                pocitadlo_i--;
              }
              else{
                Krizovka.pixels[jake_misto_v_sloupci_kontrolujeme + rozmery][sloupec] = vybarvene;
                jake_misto_v_sloupci_kontrolujeme--;
                Krizovka.pixels[jake_misto_v_sloupci_kontrolujeme + rozmery][sloupec] = nevybarvene;
                jake_misto_v_sloupci_kontrolujeme--;
                pocitadlo_i--;
                pocitadlo_i--;
              }
            }
            else{
              pocitadlo_i--;
            }
          }
        }
      }
