#include "tilescanvas.h"
#include "qdebug.h"

#include <QBitmap>
#include <QPainter>
Tilescanvas::Tilescanvas()
{

}

void Tilescanvas::generateTiles()
{
    //loading images
    spritesPix.clear();
    maskPerPix.clear();
    foreach (auto spriteName, sprites()) {
        spritesPix.insert(spriteName,new QImage(QImage("sprites/"+spriteName).scaled(cellSize(),cellSize())));
        maskPerPix.insert(spriteName,new QList<QImage*>());
    }
    maskesPix.clear();
    foreach (auto maskName, maskes()) {
        maskesPix.insert(maskName,new QImage(QImage("masks/"+maskName).scaled(cellSize(),cellSize())));
    }
    //loading generated masks for each image
    foreach (QString s, sprites()) {
        foreach (QString m, maskes()) {
            QImage *originalPix = spritesPix.value(s);
            QImage *mask1 = new QImage(*originalPix);
            QImage *mask2 = new QImage(*originalPix);
            QImage *mask3 = new QImage(*originalPix);
            QImage *mask4 = new QImage(*originalPix);

            mask1->setAlphaChannel(maskesPix.value(m)->transformed(QTransform().rotate(-90)).alphaChannel());
            mask2->setAlphaChannel(maskesPix.value(m)->transformed(QTransform().rotate(180)).alphaChannel());
            mask3->setAlphaChannel(maskesPix.value(m)->transformed(QTransform().rotate(0)).alphaChannel());
            mask4->setAlphaChannel(maskesPix.value(m)->transformed(QTransform().rotate(90)).alphaChannel());

            *maskPerPix.value(s) << mask1 << mask2 <<mask3 << mask4;

        }
    }


    qDebug() << "loggin";
    qDebug() << sprites();
    qDebug() << maskes();
    int cellNumbers = m_sprites.count()*(m_sprites.count()-1)*m_maskes.count()*4;
    gridHeight = (cellNumbers*cellSize())/m_gridWidth+(2+(1+sprites().count()/gridWidth()))*cellSize();
    emit  updateGridHeight(gridHeight);
    update();
}

void Tilescanvas::saveToImage()
{
    QPixmap mask("masks/mask1.png");
    qDebug()<< "saving";
    desPix = new QImage(cellSize()*gridWidth(),gridHeight,QImage::Format_ARGB32);
    QPainter *painter = new QPainter(desPix);
    paint(painter);
    painter->end();
    desPix->save("out.png");

}

void Tilescanvas::paint(QPainter *painter)
{   
    int icursor = 0;
    int sCount = 0;
    int firstI = 0;
    foreach (QString s, sprites()) {
        painter->drawImage((firstI%gridWidth())*cellSize(),(firstI/gridWidth())*cellSize(),*spritesPix.value(s));
        firstI++;
    }
    painter->translate(0,(1+(firstI/gridWidth())*cellSize()));
    foreach (QString s, sprites()) {
        foreach (QString s2, sprites()) {
            if(s==s2)continue;
            int j=0;
            foreach (QString m, maskes()) {

                painter->drawImage(0,0,*spritesPix.value(s));
                painter->drawImage(0,m_cellSize,*spritesPix.value(s));
                painter->drawImage(m_cellSize,0,*spritesPix.value(s));
                painter->drawImage(m_cellSize,m_cellSize,*spritesPix.value(s));

                painter->drawImage(0,0,*maskPerPix.value(s2)->at(j));
                painter->drawImage(0,m_cellSize,*maskPerPix.value(s2)->at(j+1));
                painter->drawImage(m_cellSize,0,*maskPerPix.value(s2)->at(j+2));
                painter->drawImage(m_cellSize,m_cellSize,*maskPerPix.value(s2)->at(j+3));

                painter->translate(cellSize()*2,0);
                icursor+=2;
                if(icursor>=gridWidth()){
                    painter->translate(-cellSize() * (icursor),m_cellSize*2);
                    icursor = 0;
                }
                j+= 4;
            }
        }
        sCount++;
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
