/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Quick Controls module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qquickframe_p.h"
#include "qquickframe_p_p.h"

QT_BEGIN_NAMESPACE

/*!
    \qmltype Frame
    \inherits Control
    \instantiates QQuickFrame
    \inqmlmodule QtQuick.Controls
    \ingroup containers
    \brief A frame control.

    TODO
*/

QQuickFramePrivate::QQuickFramePrivate() : contentWidth(0), contentHeight(0), frame(Q_NULLPTR)
{
}

QQuickFrame::QQuickFrame(QQuickItem *parent) :
    QQuickControl(*(new QQuickFramePrivate), parent)
{
}

QQuickFrame::QQuickFrame(QQuickFramePrivate &dd, QQuickItem *parent) :
    QQuickControl(dd, parent)
{
}

/*!
    \qmlproperty real QtQuickControls2::Frame::contentWidth

    TODO
*/
qreal QQuickFrame::contentWidth() const
{
    Q_D(const QQuickFrame);
    return d->contentWidth;
}

void QQuickFrame::setContentWidth(qreal width)
{
    Q_D(QQuickFrame);
    if (d->contentWidth != width) {
        d->contentWidth = width;
        emit contentWidthChanged();
    }
}

/*!
    \qmlproperty real QtQuickControls2::Frame::contentHeight

    TODO
*/
qreal QQuickFrame::contentHeight() const
{
    Q_D(const QQuickFrame);
    return d->contentHeight;
}

void QQuickFrame::setContentHeight(qreal height)
{
    Q_D(QQuickFrame);
    if (d->contentHeight != height) {
        d->contentHeight = height;
        emit contentHeightChanged();
    }
}

/*!
    \qmlproperty Item QtQuickControls2::Frame::frame

    TODO
*/
QQuickItem *QQuickFrame::frame() const
{
    Q_D(const QQuickFrame);
    return d->frame;
}

void QQuickFrame::setFrame(QQuickItem *frame)
{
    Q_D(QQuickFrame);
    if (d->frame != frame) {
        delete d->frame;
        d->frame = frame;
        if (frame && !frame->parentItem())
            frame->setParentItem(this);
        emit frameChanged();
    }
}

QT_END_NAMESPACE
