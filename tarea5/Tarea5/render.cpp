#include "render.h"

#include <QPainter>
#include <QPaintEvent>


Render::Render(QWidget *parent)
    : QWidget(parent)
{
    i = true;
}


/* setter */
void Render::setOperations(const QList<Operation> &operations)
{
    this->operations = operations;
    update();
}

/* setter */
void Render::setShape(const QPainterPath &shape)
{
    this->shape = shape;
    update();
}


QSize Render::minimumSizeHint() const
{
    return QSize(182, 182);
}

QSize Render::sizeHint() const
{
    return QSize(232, 232);
}


/* Cada que llega un evento esta función actualiza todo */
void Render::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(event->rect(), QBrush(Qt::darkRed));

    /* Se divide esntre estos numeros para uqe siemrpe esté en el centro*/
    painter.translate(this->width()/3, this->height()/2.5);
    painter.save();
    transformPainter(painter);
    drawShape(painter);
    painter.restore();
    //drawOutline(painter);
    transformPainter(painter);
}


void Render::drawOutline(QPainter &painter)
{
    painter.setPen(Qt::red);
    painter.setPen(Qt::DashLine);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(0, 0, 100, 100);
}

void Render::drawShape(QPainter &painter)
{
    painter.fillPath(shape, Qt::blue);
}

void Render::transformPainter(QPainter &painter)
{
    for (int i = 0; i < operations.size(); ++i)
    {
        switch (operations[i])
        {
        case Translate:
            painter.translate(50, 50);
            break;
        case ZoomIn:
            painter.scale(2, 2);
            break;
        case ZoomOut:
            painter.scale(0.5, 0.5);
            break;
        case Rotate:
            painter.rotate(65);
            break;
        case ReflectionX:
            painter.scale(1,-1);
            break;
        case ReflectionY:
            painter.scale(-1,1);
            break;
        case Reflection:
            painter.scale(-1,-1);
            break;
        case NoTransformation:
        default:
            ;
        }
    }
}
