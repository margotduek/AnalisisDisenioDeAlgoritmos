/*
  Margot Duek
  A01021226
  Análisis y diseño de algoritmos
  - Supongamos que tenemos n hombres y n mujeres y dos matrices M y H que contienen
    las preferencias de los unos por los otros. Más concretamente, la fila M[i,·] es una
    ordenación (de mayor a menor) de las mujeres según las preferencias del i-ésimo
    hombre y, análogamente, la fila H[i,·] es una ordenación (de mayor a menor) de los
    hombres según las preferencias de la i-ésima mujer.
    Diseñe un algoritmo que encuentre, si es que existe, un emparejamiento de hombres y
    mujeres tal que todas las parejas formadas sean estables. Una pareja (h,m) es estable si
    no se da ninguna de estas dos circunstancias:
      • Existe una mujer m’ (que forma la pareja (h’,m’)) tal que el hombre h la prefiere
        sobre la mujer m y además la mujer m’ también prefiere a h sobre h’.
      • Existe un hombre h” (que forma la pareja (h”,m”)) tal que la mujer m lo prefiere
        sobre el hombre h y además el hombre h” también prefiere a m sobre la mujer m”. 
*/
