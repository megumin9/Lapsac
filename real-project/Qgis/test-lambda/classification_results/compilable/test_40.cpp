
#include <bits/stdc++.h>
#include <initializer_list>
#include <utility>

namespace Qgis {
    enum class LayerType {
        Annotation, Vector, PointCloud, Mesh, VectorTile, Raster, Group, Plugin
    };
}

class QObject {
public:
    virtual ~QObject() {}
};

class QgsMapLayer : public QObject {
public:
    virtual Qgis::LayerType type() const = 0;
};

class QgsVectorLayer : public QgsMapLayer {
public:
    int geometryType() const;
};

template<typename K, typename V>
class QMap {
public:
    QMap(std::initializer_list<std::pair<const K, V>> init) {}
    V value(const K &key) const { return V(); }
};

template<typename T>
T qobject_cast(QObject *ptr) {
    return nullptr;
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(QgsMapLayer *a, QgsMapLayer *b)
{
  const static QMap<Qgis::LayerType, int> layerTypeOrdering = {
    { Qgis::LayerType::Annotation, -1 },
    { Qgis::LayerType::Vector, 0 },
    { Qgis::LayerType::PointCloud, 1 },
    { Qgis::LayerType::Mesh, 2 },
    { Qgis::LayerType::VectorTile, 3 },
    { Qgis::LayerType::Raster, 4 },
    { Qgis::LayerType::Group, 5 },
    { Qgis::LayerType::Plugin, 6 },
  };

  if ( a->type() == Qgis::LayerType::Vector && b->type() == Qgis::LayerType::Vector )
  {
    QgsVectorLayer *av = qobject_cast<QgsVectorLayer *>( a );
    QgsVectorLayer *bv = qobject_cast<QgsVectorLayer *>( b );
    return av->geometryType() > bv->geometryType();
  }

  return layerTypeOrdering.value( a->type() ) > layerTypeOrdering.value( b->type() );
}

void test1(QgsMapLayer *a, QgsMapLayer *b, QgsMapLayer *c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
ConsistencyChecker();
}

void test2(QgsMapLayer *a, QgsMapLayer *b, QgsMapLayer *c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
TransiveChecker();
}

void test3_1(QgsMapLayer *a, QgsMapLayer *b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(QgsMapLayer *a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}
