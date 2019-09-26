#include "tilescanvas.h"
#include "qdebug.h"

#include <QBitmap>
#include <QPainter>
Tilescanvas::Tilescanvas()
{

}

void Tilescanvas::generateTiles()
{

    qDebug() << "loggin";
    qDebug() << sprites();
    qDebug() << maskes();
    update();
}

void Tilescanvas::saveToImage()
{
    QPixmap mask("masks/mask1.png");
    qDebug()<< "saving";
    desPix = new QPixmap(300,300);
    QPainter *painter = new QPainter(desPix);
    paint(painter);
    painter->end();
    desPix->setMask(mask.scaled(300,300).mask());
    desPix->save("out.png");

}

void Tilescanvas::paint(QPainter *painter)
{   
    foreach (QString s, sprites()) {
        for (int i = 0; i < gridWidth(); ++i) {
            for (int j = 0; j < gridWidth(); ++j) {
                painter->drawImage(j*cellSize(),i*cellSize(),QImage("sprites/"+s).scaled(cellSize(),cellSize()));
            }
        }
    }   
}



QStringList Tilescanvas::sprites() const
{
    return m_sprites;
}

QStringList Tilescanvas::maskes() const
{
    return m_maskes;
}

int Tilescanvas::cellSize() const
{
    return m_cellSize;
}

int Tilescanvas::gridWidth() const
{
    return m_gridWidth;
}

void Tilescanvas::setSprites(QStringList sprites)
{
    if (m_sprites == sprites)
        return;

    m_sprites = sprites;
    emit spritesChanged(m_sprites);
}

void Tilescanvas::setMaskes(QStringList maskes)
{
    if (m_maskes == maskes)
        return;

    m_maskes = maskes;
    emit maskesChanged(m_maskes);
}

void Tilescanvas::setCellSize(int cellSize)
{
    if (m_cellSize == cellSize)
        return;

    m_cellSize = cellSize;
    emit cellSizeChanged(m_cellSize);
}

void Tilescanvas::setGridWidth(int gridWidth)
{
    if (m_gridWidth == gridWidth)
        return;

    m_gridWidth = gridWidth;
    emit gridWidthChanged(m_gridWidth);
}
