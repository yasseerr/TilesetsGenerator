#ifndef TILESCANVAS_H
#define TILESCANVAS_H

#include <QQuickPaintedItem>



class Tilescanvas : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QStringList sprites READ sprites WRITE setSprites NOTIFY spritesChanged)
public:
    Tilescanvas();
    Q_INVOKABLE
    void generateTiles();

public:
    virtual void paint(QPainter *painter) override;
    QStringList sprites() const;
public slots:
    void setSprites(QStringList sprites);
signals:
    void spritesChanged(QStringList sprites);
private:
    QStringList m_sprites;
};



#endif // TILESCANVAS_H
