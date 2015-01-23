#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QObject>
#include <QVector3D>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include "globals.h"
#include <memory>

typedef struct DrawInfo {
    QMatrix4x4 View;
    QMatrix4x4 Projection;
    GLenum mode;
} DrawInfo;

/*! \class Geometry
 * \brief Base de tous les acteurs
 *
 * Cette classe est une base gerant de rendu d'un buffer de vertices.
 * Ses 3 propriétés position, orientation et scale permettent de déplacer l'objet.
 */
class Geometry : public QObject
{
    Q_OBJECT
public:
    Geometry(QObject* parent = nullptr);
    void draw(const DrawInfo &info);
    propSig(QVector3D, position, moved)
    propSig(QQuaternion, orientation, rotated)
    propSig(QVector3D, scale, scaled)
protected:
    QMatrix4x4 transform();
    virtual std::vector<GLfloat>& getVertices() = 0;
    virtual std::vector<GLfloat>& getColors() = 0;
    virtual std::vector<quint32>& getIndices() = 0;
    static void initProgram(Geometry *self, QObject *parent);
private:
    // Instances
    static int s_instances;
    static QOpenGLShaderProgram* s_program;
    static QOpenGLBuffer* s_vertexBuffer;
    static QOpenGLBuffer* s_colorBuffer;
    //static QOpenGLBuffer* s_normalBuffer;
    static QOpenGLBuffer* s_indexBuffer;
};

#endif // GEOMETRY_H