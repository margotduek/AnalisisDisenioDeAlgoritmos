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
    operationComboBoxes[i]->addItem(tr("Sin transforación"));
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
    layout->addWidget(operationComboBoxes[i], 0, i+1);
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
  poli.moveTo(-45.0, -20.0);
  poli.lineTo(0.0, -45.0);
  poli.lineTo(45.0, -20.0);
  poli.lineTo(45.0, 45.0);
  poli.lineTo(-45.0, 45.0);
  poli.lineTo(-45.0, -20.0);
  poli.addRect(15.0, 5.0, 20.0, 35.0);
  poli.addRect(-35.0, -15.0, 25.0, 25.0);

  QPainterPath text;
  QFont font;
  font.setPixelSize(40);
  QRect fontBoundingRect = QFontMetrics(font).boundingRect(tr("Hello"));
  text.addText(-QPointF(fontBoundingRect.center()), font, tr("Hello"));

  shapes.append(cuadrado);
  shapes.append(arco);
  shapes.append(poli);


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
