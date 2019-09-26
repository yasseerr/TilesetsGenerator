#ifndef TILESCANVAS_H
#define TILESCANVAS_H

#include <QQuickPaintedItem>



class Tilescanvas : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QStringList sprites READ sprites WRITE setSprites NOTIFY spritesChanged)
    Q_PROPERTY(QStringList maskes READ maskes WRITE setMaskes NOTIFY maskesChanged)
    Q_PROPERTY(int cellSize READ cellSize WRITE setCellSize NOTIFY cellSizeChanged)
    Q_PROPERTY(int gridWidth READ gridWidth WRITE setGridWidth NOTIFY gridWidthChanged)

public:
    Tilescanvas();
    Q_INVOKABLE
    void generateTiles();
    Q_INVOKABLE
    void saveToImage();

public:
    virtual void paint(QPainter *painter) override;
    QStringList sprites() const;
    QStringList maskes() const;
    int cellSize() const;
    int gridWidth() const;

public slots:
    void setSprites(QStringList sprites);
    void setMaskes(QStringList maskes);
    void setCellSize(int cellSize);
    void setGridWidth(int gridWidth);

signals:
    void spritesChanged(QStringList sprites);
    void maskesChanged(QStringList maskes);
    void cellSizeChanged(int cellSize);
    void gridWidthChanged(int gridWidth);
    void updateGridHeight(int h);


private:
    QStringList m_sprites;
    QPixmap *desPix;
    QStringList m_maskes;
    int m_cellSize;
    int m_gridWidth;

    //to work with
    int gridHeight;
    QMap<QString,QPixmap*> spritesPix;
    QMap<QString,QPixmap*> maskesPix;
    QMap<QString,QList<QPixmap*>*> maskPerPix;
};



#endif // TILESCANVAS_H
