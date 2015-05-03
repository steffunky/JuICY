# Fichier

Tout fichier commence par :

    /**
    *
    * @File : nomfichier.extension
    *
    * @Authors : Auteur
    *
    * @Date : Datedecréation
    *
    * @Version : V1.0 (A incrementer
    *
    * @Synopsis : ...
    **/

Un bloc s'écrit :
    int main(){
        //code
    } //main()
ou
    int main()
    {
        //code
    } //main()
    
Une utilisation intelligente des namepspace. (ex: TEA::crypt(), SHA::crypt()).
Commenter le code un peu "rigolo" :-)
# Classe

Les .h commencent par :

    #ifndef __NOM_CLASSE_H__
    #define __NOM_CLASSE_H__
et se termine par
    #endif /* __NOM_CLASSE_H__ */
Faire précéder le nom de la donnée membre des caractères m_ : 

    class Bird{
        int m_NbAiles;
    }
    
PAS de using namespace dans les headers
