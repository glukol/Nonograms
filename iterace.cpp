#include "posun.cpp"

void iterace_na_sloupce(){

	int sloupec, radek;
	int ktice_v_zadani;
	int kde_se_nachazi_posledni_nalezena_ktice;
	int pocet_policek_ktice;

	for (sloupec = 1; sloupec <= pocet_sloupcu_krizovky; sloupec++){
		// pro kazdy sloupec krizovky opakuj ...

		radek = pocet_radku_krizovky;
		// zacneme na poslednim radku

		for (ktice_v_zadani = Zadani_vrch.pixels[sloupec][0]; ktice_v_zadani >= 1; ktice_v_zadani--){
			// v "zadani_vrch[sloupec, 0]" je ulozeno kolik k-tic se nachazi
			// v sloupci s indexem "sloupec"

			// zjistujeme zda se kazka k-tice nachazi ve sloupci

			kde_se_nachazi_posledni_nalezena_ktice = radek;
			// poznacime si, kde sme nachazi posledni volne misto, kam muzeme
			// zapisovat, resp. odkud hledame novou k-tici

			while ((Krizovka.pixels[radek + rozmery][sloupec] != vybarvene) && (radek > 0)){

				Krizovka.pixels[radek + rozmery][sloupec] = nevybarvene;
				radek--;
				// preskocime nevybarvena policka
			}

			if (radek == 0){
				radek = kde_se_nachazi_posledni_nalezena_ktice;
				// jestlize sme zacatek dalsi k-tice nenasli, vratime se na podledni
				// volne policko a zacneme tam zapisovat novou k-tici
			}

			for (pocet_policek_ktice = 1; pocet_policek_ktice <= Zadani_vrch.pixels[sloupec][ktice_v_zadani]; pocet_policek_ktice++){
				Krizovka.pixels[radek + rozmery][sloupec] = vybarvene;
				radek--;
				// doplnime novou k-tici do krizovky - podle toho kde se nachazime
				// bud k-tici stavime uplne od zacatku (jestlize zadne dalsi vybarvene)
				// policko v krizovce nebylo, a jestlize sme takove nasli, prehlasime
				// ho za zacatek nove k-tice a pripadne chybejici policka k-tice doplnime
			}


			if (ktice_v_zadani > 1){
				Krizovka.pixels[radek + rozmery][sloupec] = nevybarvene;
				radek--;
				// jestlize to nebyla posledni chybejici k-tice, pridame za ni mezeru
				// a presuneme se na neblizsi misto, kde muze zacinat nova
			}

			// opakujeme dokud nam nedojdou k-tice ...

		}

		while (radek >= 1){
			Krizovka.pixels[radek + rozmery][sloupec] = konec;
			radek--;
		}
		radek++;
		// vynuluje pripadny dalsi bordel v krizovke

		// doplnovanim k-tic sme se vsak mohli dostat mimo krizovky a tak tento
		// nedostatek musime napravit poposouvanim

		if (radek < 1){
			posun(radek, sloupec);
		}

		//{while radek < 1 do
		//begin
		//  posun(radek, sloupec);
		//  Inc(radek);
		//end;    }

		// poposouva precuhujici k-tice spatky do krizovky

		// opakujeme dokud nedojdou sloupce ...
	}
}