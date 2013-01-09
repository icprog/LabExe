#ifndef GCHANNELGRAPHICSITEM_H
#define GCHANNELGRAPHICSITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsLayoutItem>
class GnewChannel;
class GSynchEvent;

/////////////////////////////////////////////////////////////////////
//! \brief The GnewChannelGraphicsItem class defines defines the graphical representation of a Channel for the GSequenceGraphicsScene. 
/*!
It inherits QGraphicsLayoutItem so that it can be placed in a layout in the scene. 
It resize itself to fill the whole GSequence::Length() in the GSequenceScene. For this, sizeHint() and setGeometry() have been reimplemented.
*/
class GnewChannelGraphicsItem : public QGraphicsRectItem, public QGraphicsLayoutItem
{
public:
	//! ctor. You must pass the Channel represented by this GraphicsRectItem.
	GnewChannelGraphicsItem(GnewChannel* theChannel);
	~GnewChannelGraphicsItem();

	//! Returns a pointer to the Channel represented by this GraphicsRectItem.
	GnewChannel* Channel() const { return m_pChannel; }

public:
	//! reimplemented from QGraphicsLayoutItem
	virtual void setGeometry( const QRectF & rect );

protected:
	//! reimplemented from QGraphicsLayoutItem
	virtual QSizeF sizeHint( Qt::SizeHint which, const QSizeF & constraint = QSizeF() ) const;
	//! reimplemented from QGraphicsItem
	virtual void mousePressEvent( QGraphicsSceneMouseEvent * event );
	//! Reimplemented from QGraphicsItem. Calls the GnewChannel function to handle that.
	void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

private:
	//! pointer to the Channel represented by this GraphicsRectItem.
	GnewChannel* m_pChannel;
};

#endif // GCHANNELGRAPHICSITEM_H
