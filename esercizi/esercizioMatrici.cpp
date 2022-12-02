#include <bits/stdc++.h>

using namespace std;

double value  (double n){
	if(n == INT_MIN)
		return 0;
	return n;
}

int main(){

  int righe = 10;
  int colonne = 10;

  //QUESTO PROGRAMMA RISOLVERA' AL PIU' SISTEMI LINEARI DI 100 EQUAZIONI A 10 INCOGNITE (basta modificare i numeri qui per aumentare la potenza)

  double m[righe][colonne];
  double s[10]; //QUESTA LA SI PUO' VEDERE COME LA COLONNA DELLE SOLUZIONI
  
  //IMPOSTO A INT_MIN IL VALORE DI DEFAULT COME TECNICA PER COMPRENDERE IL NUMERO DI RIGHE EFFETTIVE DI UNA MATRICE
  
  //NEL CASO IN CUI AVESSI LA SFIGA DI AVERE UN VALORE DEI COEFFICIENTI ALL'INTERNO DELLA MATRICE COMPLETA AVRO' UN ERRORE NON INDIFFERENTE

  for(int i=0; i<righe; i++){
    for(int j=0; j<colonne; j++)
      m[i][j] = INT_MIN;        
  }

  //ORA MI OCCUPO DELL'INSERIMENTO DI DATI DA PARTE DELL'UTENTE TRAMITE UNA SCELTA ITERATA FINCHE' IL CHAR RESTA S OPPURE ARRIVO ALLA CENTESIMA EQUAZIONE
  //NOTARE CHE LA STESSA OPERAZIONE ANDRA' SVOLTA SULLE COLONNE 
  
  int k_r = 1; //keep rows
  int k_c = 1; //keep columns
  int c_r = 0; //count rows
  int c_c = 0; //count columns

  while(k_r == 1 && c_r < righe){
    
    cout<<"EQUAZIONE NUMERO "<< c_r + 1 <<" : "<<endl;
    
    while(k_c == 1 && c_c < colonne){

      cout<<"TERMINE X_"<< c_c + 1 <<": ";
      cin>>m[c_r][c_c];
      cout<<"ALTRO COEFFICIENTE? (1 yes other no)"<<endl;
      cin>>k_c;
      c_c++;
      
    }
    cout<<"VALORE EQUAZIONE: ";
    cin>>s[c_r];
    k_c = 1;
    c_c = 0;
    cout<<"ALTRA EQUAZIONE? (1 yes other no)"<<endl;
    cin>>k_r;
    c_r++;
    
  }

  int n_eq = c_r-1; //QUI MI SALVO IL NUMERO DI EQUAZIONI INSERITE
  
  //FUNZIONE DI STAMPA SPECIALE

  cout<<endl;
  
  for(int i=0; i<righe; i++){
    for(int j=0; j<colonne; j++){
      if(m[i][j] != INT_MIN)
        cout<<m[i][j]/*<<"x_"<<j+1*/<<" ";
    }
    if(m[i][0] != INT_MIN)
      cout<<endl;
  }

  //VADO A CERCARE QUALE E' L'INCOGNITA MAGGIORE (SE VOGLIAMO X_N IN UN SISTEMA CON N EQUAZIONI)

  int coef_max = 0;

  c_r = 0;
  c_c = 0;

  while(c_r < righe){
    while(c_c < colonne){
      if(m[c_r][c_c] != INT_MIN){
        if(coef_max < c_c)
          coef_max = c_c;
      }
      else
        c_c = 9;
      c_c++;
    }
    c_c = 0;
    c_r ++;
  }

  //cout<<"COEFFICIENTE MASSIMO: "<<coef_max<<endl;

  //ORA POSSO FINALMENTE SCRIVERE LA MATRICE DEI COEFFICENTI CON VALORI O 0 O DIVERSI DA 0
  
  for (int i=0; i<=n_eq; i++){
    for(int j=0; j<=coef_max; j++){
      if(m[i][j] == INT_MIN)
        m[i][j] = 0;
    }
  }

  //FUNZIONE DI STAMPA SPECIALE

  cout<<endl;
  
  for(int i=0; i<righe; i++){
    for(int j=0; j<colonne; j++){
      if(m[i][j] != INT_MIN)
        cout<<m[i][j]/*<<"x_"<<j+1*/<<" ";
    }
    if(m[i][0] != INT_MIN)
      cout<<endl;
  }

	//ORA DEVO TRASFORMARE UNA MATRICE IN UNA MATRICE SCALA

  int r = 0;
	bool found = false;

	for(int j = 0; j<= coef_max; j++){
		for(int i = r; i<= n_eq; i++){
			if(m[i][j] != 0	&& found == false){

				//cout<<endl<<"ORA AVVIENE UNA Oe1"<<endl;
				
				for(int l=0; l<=coef_max; l++){
					double t = m[i][l];
					m[i][l] = m[r][l];
					m[r][l] = t;
					t = s[i];
					s[i] = s[r];
					s[r] = t;		
				}

				found = true;
				r ++;
				
			}else if(m[i][j] != 0 && found == true){

				//cout<<endl<<"ORA AVVIENE UNa Oe3"<<endl;

				double k = m[i][j] / m[r-1][j];
				k *= -1;
				
				for(int l=j; l<= coef_max; l++){
					m[i][l] += (m[r-1][l]*k);
				}
				s[i] += (s[r-1]*k);
				
			}
			
		}

		found = false;
		
	}

	//ITERIAMO LE COLONNE
	
 //FUNZIONE DI STAMPA SPECIALE

  cout<<endl;
  for(int i=0; i<righe; i++){
    for(int j=0; j<colonne; j++){
      if(m[i][j] != INT_MIN)
        cout<<m[i][j]/*<<"x_"<<j+1*/<<" ";
    }
		
    if(m[i][0] != INT_MIN){
			cout<<" "<<s[i];
			cout<<endl;
		}
      
  }

	//ORA RISOLVO IL SISTEMA LINEARE
    /* 
    double sol[coef_max];	//LE SOLUZIONI SONO PARI AL NUMERO DI EQUAZIONI TOTALI, PERO' IL NUMERO DI VARIABILI E' PARI AL NUMERO DI COLONNE

	//INIZIALIZZO LE SOLUZIONI A INT_MIN

	for(int i=0; i<coef_max; i++)
		sol[i] = INT_MIN;

	//ORA MAN MANO ITERO LA MATRICE DAL BASSO VERSO L'ALTO RISOLVENDO L'EQUAZIONE UN PASSO ALLA VOLTA

	for(int i=n_eq; i>=0; i--)	//	qui c'è un errore
	{
		int j = 0;
		while(m[i][j]==0)
			j++;
		int somma = 0;
		for(int l=j+1; l<=coef_max; l++){
			somma -= value(sol[l])*m[i][l];
		}
		sol[j] = (somma+s[i])/m[i][j];
	}

	//STAMPO SEMPLICEMENTE IL VETTORE DELLE SOLUZIONI IN ORDINE
	//NOTA CHE SE HO SOLUZIONI CON VALORI IMPROPNIBILI NON E' ALTRO CHE IL MODO CHE IL COMPILATORE HA PER ESPRIMIRE L'IMPOSSIBILITA' DELLA RISOLUZIONE DEL SISTEMA LINEARE
	cout<<endl;
	
	for(int i=0; i<=coef_max; i++){
		
		if(sol[i] != INT_MIN)
			cout<<"X"<<i<<": "<<sol[i]<<endl;
	}

	cout<<endl;
*/
  return 0;
  
}