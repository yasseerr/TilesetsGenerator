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
        painter->drawImage(0,0,QImage("sprites/"+s));
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
