#include "window.h"

#include <QComboBox>
#include <QGridLayout>

Window::Window()
{
  //Se crea un nuevo render area
  originalRenderArea = new Render();

  // Se agrga un nuevo combo box
  shapeComboBox = new QComboBox;
  //Se agregan las figuras
  shapeComboBox->addItem(tr("cuadrado"));
  shapeComboBox->addItem(tr("curva"));
  shapeComboBox->addItem(tr("poligono"));
  shapeComboBox->addItem(tr("figuras"));
  shapeComboBox->addItem(tr("triangulo"));
  shapeComboBox->addItem(tr("circulo"));


  /* es donde se define el cudrito donde van a estar las figuras, para que la
     hora de agrandar no se salga del cuadrito y no invada el del otro*/
  QGridLayout *layout = new QGridLayout;
  layout->addWidget(originalRenderArea,0,0);
  layout->addWidget(shapeComboBox, 1,0);

  for (int i = 0; i < NumTransformedAreas; i++) {
    /* Esto es lo que genera cada uno de los cuadritos, yo ya lo había declarado
    en el .h en este caso yo declaré que son 4 */
    transformedRenderArea[i] = new Render;

    operationComboBoxes[i] = new QComboBox;
    operationComboBoxes[i]->addItem(tr("Sin transforacion"));
    operationComboBoxes[i]->addItem(tr("Ratocaión"));
    operationComboBoxes[i]->addItem(tr("Zoom in"));
    operationComboBoxes[i]->addItem(tr("Zoom Out"));
    operationComboBoxes[i]->addItem(tr("Translación"));
    operationComboBoxes[i]->addItem(tr("Reflexión"));

    /* conecta la operación seleccionada con la accion al cudrito en el que estás */
    connect(operationComboBoxes[i], SIGNAL(activated(int)),
          this, SLOT(operationChanged()));

    /* Esto está agregando cada cuadrito más uno*/
    layout->addWidget(transformedRenderArea[i], 0, i + 1 );
    layout->addWidget(operationComboBoxes[i], 1, i+1);
  }

  setLayout(layout);
  setupShapes();
  shapeSelected(0); // este es el dibujo seleccionado

  setWindowTitle("Transformaciones");
}


void Window::setupShapes(){
  QPainterPath cuadrado;
  /*esta linea colorea la figura*/
  cuadrado.setFillRule(Qt::WindingFill);
  cuadrado.moveTo(-20,-20);
  cuadrado.lineTo(20,-20);
  cuadrado.lineTo(20,20);
  cuadrado.lineTo(-20,20);
  cuadrado.lineTo(-20,-20);


  /*Revisar si si sirve*/
  QPainterPath arco;
  arco.arcMoveTo(0,0,50,50,20);
  arco.arcTo(0,0,50,50,20, 90);


  QPainterPath poli;
  poli.moveTo(-20.0, -20.0);
  poli.lineTo(20.0, -20.0);
  poli.lineTo(10.0, 20.0);
  poli.lineTo(-10.0, 20.0);
  poli.lineTo(-20.0, -20.0);


  QPainterPath figuras;
  figuras.moveTo(10.0, -20);
  figuras.lineTo(20, 20);
  figuras.lineTo(30, -20);
  figuras.lineTo(10, -20);
  figuras.moveTo(35.0, 35.0);
  figuras.lineTo(-25.0, 35.0);
  figuras.lineTo(10.0, -25.0);
  figuras.lineTo(-10.0, -25.0);
  figuras.lineTo(35.0, 35.0);


  QPainterPath triangulo;
  triangulo.moveTo(10.0, -20);
  triangulo.lineTo(20, 20);
  triangulo.lineTo(30, -20);
  triangulo.lineTo(10, -20);

  QPainterPath circulo;
  circulo.addEllipse(-50.0, -50.0, 100.0, 100.0);

  shapes.append(cuadrado);
  shapes.append(arco);
  shapes.append(poli);
  shapes.append(figuras);
  shapes.append(triangulo);
  shapes.append(circulo);



  connect(shapeComboBox, SIGNAL(activated(int)), this, SLOT(shapeSelected(int)));
}

void Window::operationChanged()
{
  /* Se le asignan las operaciones al menu */
  static const Operation operationTable[] = {
      NoTransformation, Rotate, ZoomIn, ZoomOut, Translate, Reflection
  };

  /* esto es el enlace del menu con la funcion */
  QList<Operation> operations;
  for (int i = 0; i < NumTransformedAreas; ++i) {
      int index = operationComboBoxes[i]->currentIndex();
      operations.append(operationTable[index]);
      transformedRenderArea[i]->setOperations(operations);
  }
}

/* esto es para que se pinte en cada cuadrito */
void Window::shapeSelected(int index)
{
  QPainterPath shape = shapes[index];
  originalRenderArea->setShape(shape);
  for (int i = 0; i < NumTransformedAreas; ++i)
      transformedRenderArea[i]->setShape(shape);
}
