#include "tilescanvas.h"
#include "qdebug.h"

#include <QPainter>
Tilescanvas::Tilescanvas()
{

}

void Tilescanvas::generateTiles()
{

    qDebug() << "loggin";
    qDebug() << sprites();
    update();
}

void Tilescanvas::saveToImage()
{
    QImage desImage("out.png","png");
    QPainter *painter = new QPainter(&desImage);
    paint(painter);
    painter->save();
}

void Tilescanvas::paint(QPainter *painter)
{   
    foreach (QString s, sprites()) {
        //painter->drawImage(0,0,QImage("sprites/"+s));
    }   
}



QStringList Tilescanvas::sprites() const
{
    return m_sprites;
}

void Tilescanvas::setSprites(QStringList sprites)
{
    if (m_sprites == sprites)
        return;

    m_sprites = sprites;
    emit spritesChanged(m_sprites);
}
