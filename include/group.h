#ifndef GROUP_H
#define GROUP_H

#include <QVector>
#include <geometry.h>

/*! \class Group
 * \brief Groupe de geometries
 *
 * Toute les géometries enfant de cet objet seront affichés avec une transformation relative a celle du groupe.
 */
class Group : public Geometry
{
public:
    Group(QObject* parent = nullptr);
    void draw(const DrawInfo& info) Q_DECL_OVERRIDE;
};

#endif // GROUP_H
