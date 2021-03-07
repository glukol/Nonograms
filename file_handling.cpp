
void okupiruj_subor(string meno_vstup, string meno_vystup){

	ifstream soubor_vstup;
	ofstream soubor_vystup;
	string radek;

	soubor_vstup.open(meno_vstup);
	soubor_vystup.open(meno_vystup);

	while (getline(soubor_vstup, radek)){
		soubor_vystup << radek << '\n';
	}

	soubor_vstup.close();
	soubor_vystup.close();
}

void prepis_vysledku(string jmeno, string slozka, string pripona){

	ofstream prepis_reseni;
	ifstream reseni;
	char znak;

	reseni.open(slozka + to_string(pocet_radku_krizovky) + pripona);
	prepis_reseni.open(jmeno);

	while (reseni >> znak){
		for (int pocitadlo_i = 1; pocitadlo_i <= pocet_sloupcu_krizovky; pocitadlo_i++){
			//Read(reseni, znak);
			if (znak == vybarvene){
				prepis_reseni << 'X';
			}
			else if ((znak == nevybarvene) || (znak == konec)){
				prepis_reseni << ' ';
			}
			reseni >> znak;
		}
		//readln(reseni);   // zakomentuj pro binarni soubory
		prepis_reseni << '\n';
	}

	reseni.close();
	prepis_reseni.close();
}

/* procedure uklid_po_sobe(slozka_moznosti, pripona_moznosti, slozka_prepis,
    pripona_prepis, slozka_hotove, pripona_hotove, a, b, c, prip_bok, prip_vrch: string);
  begin
    vymaz_stare_soubory(slozka_moznosti, pripona_moznosti);
    createdir(slozka_moznosti);
    vymaz_stare_soubory(slozka_prepis, pripona_prepis);
    createdir(slozka_prepis);
    vymaz_stare_soubory(slozka_hotove, pripona_hotove);
    createdir(slozka_hotove);

    DeleteFile(a + prip_bok);
    DeleteFile(a + prip_vrch);
    DeleteFile(b + prip_bok);
    DeleteFile(b + prip_vrch);
    DeleteFile(c + prip_bok);
    DeleteFile(c + prip_vrch);
  end;
*/

/*	procedure obrazek(meno: string);
	var
		x, y: integer;
		vystupny_obrazek: tbitmap;
		prepsane_reseni: Text;
		znak: char;
	begin
		Assign(prepsane_reseni, meno + '.txt');
		reset(prepsane_reseni);

		vystupny_obrazek := TBitmap.Create;
		vystupny_obrazek.PixelFormat := pf4bit;
		vystupny_obrazek.SetSize(pocet_sloupcu_krizovky * natahnuti_obrazka,
		pocet_radku_krizovky * natahnuti_obrazka);
		vystupny_obrazek.canvas.brush.Style := BSsolid;
		vystupny_obrazek.canvas.pen.color := clwhite;

		for y := 0 to pocet_radku_krizovky - 1 do
		begin
		for x := 0 to pocet_sloupcu_krizovky - 1 do
		begin
			Read(prepsane_reseni, znak);
			case znak of
			'X':
			begin
				vystupny_obrazek.canvas.brush.Color := CLBlack;
				vystupny_obrazek.canvas.Rectangle(x * natahnuti_obrazka,
				y * natahnuti_obrazka, (x + 1) * natahnuti_obrazka,
				(y + 1) * natahnuti_obrazka);
			end;
			' ':
			begin
				vystupny_obrazek.canvas.brush.Color := ClWhite;
				vystupny_obrazek.canvas.Rectangle(x * natahnuti_obrazka,
				y * natahnuti_obrazka, (x + 1) * natahnuti_obrazka,
				(y + 1) * natahnuti_obrazka);
			end;
			end;
		end;
		readln(prepsane_reseni);
		end;
		Close(prepsane_reseni);

		//DeleteFile('Vystup.bmp');
		vystupny_obrazek.SaveToFile(meno + '.bmp');
		vystupny_obrazek.Free;   // }
	end;
*/
