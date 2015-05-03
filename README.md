# JuICY
Crypted Xmpp / IRC portable client | Jabber ∪ Irc enCrYpted
Fonctionalités : 
    Priorité : 
        1 : Obligatoire
        2 : Passable
        3 : À faire quand ya le temps
        4 : Juste une idée
1    XMPP
	1 OTR
	1 End to End
	2 Salles de discutions
	2 FileTransfert
	2 Bonjour/Zéroconf
	4 TicTacToe
	4 Emoticons (beer)
1 Chiffrement historique
	1 TinyEncryption
	4 Choix parmis plusieurs méthodes
1 Passphrase
1 IRC
	1 Liste serveurs 
	1 Enregistrer serveurs / Autoconnexion
	2 Liste amis
	3 FileTransfert
	3 DCC
3 Fichier de conf pour personnaliser
	4 Passphrase oui/non
	2 Expiration passphrase
	2 Expiration de session
	1 Conservation des logs
	1 Connexion auto
	4 Allumer au démarrage
4 VOIP

Technologies :
    GUI : Gtkmm 
    Cryptage passphrase : sha256 +salt
    Cryptage fichiers : TEA
