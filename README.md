# Curve-Tracer-Basic-Partie-2-BREADBOARD-DFTA272
Essais de validation sur breadboard

Cette étape du projet valide en conditions réelles le fonctionnement du traceur de courbes pour transistors NPN après la phase de simulation présentée dans DFTA271.

Objectif

Tracer sur oscilloscope analogique en mode XY :

IC=f(VCE)

pour différentes valeurs de courant de base.

Une future évolution pourrait également permettre :

IC=f(IB)

avec tension VCE réglable manuellement.

Architecture actuelle
Seeed Studio XIAO SAMD21
DAC intégré pour générer la rampe VCE
6 niveaux de courant de base
commutation des résistances via MOSFETs canal N
générateur de courant high-side
conversion courant collecteur → tension
affichage sur oscilloscope analogique XY
Changements depuis DFTA271

Abandon de la logique haute impédance sur les GPIO.

Nouvelle architecture plus robuste :

toutes les sorties au repos à LOW
activation d’une seule voie à HIGH
commutation via MOSFETs canal N

Cette solution simplifie fortement le pilotage et améliore la fiabilité.

Résultats

Les premiers essais sur breadboard permettent déjà :

d’obtenir des familles de courbes cohérentes
de visualiser les différences entre transistors
de détecter certains comportements atypiques
de valider l’architecture avant passage sur PCB
Prochaine étape

DFTA273 : réalisation du PCB final.
