#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

static const unsigned char qt_resource_tree[] = {
0,
0,0,0,0,2,0,0,0,6,0,0,0,1,0,0,0,
8,0,2,0,0,0,2,0,0,0,19,0,0,0,68,0,
2,0,0,0,4,0,0,0,15,0,0,1,82,0,2,0,
0,0,3,0,0,0,12,0,0,0,204,0,2,0,0,0,
3,0,0,0,9,0,0,1,60,0,0,0,0,0,1,0,
0,0,0,0,0,1,250,0,2,0,0,0,2,0,0,0,
7,0,0,2,70,0,0,0,0,0,1,0,0,0,0,0,
0,2,20,0,0,0,0,0,1,0,0,0,0,0,0,1,
0,0,0,0,0,0,1,0,0,0,0,0,0,0,226,0,
0,0,0,0,1,0,0,0,0,0,0,1,22,0,0,0,
0,0,1,0,0,0,0,0,0,1,108,0,0,0,0,0,
1,0,0,0,0,0,0,1,200,0,0,0,0,0,1,0,
0,0,0,0,0,1,160,0,0,0,0,0,1,0,0,0,
0,0,0,0,120,0,0,0,0,0,1,0,0,0,0,0,
0,0,84,0,0,0,0,0,1,0,0,0,0,0,0,0,
144,0,0,0,0,0,1,0,0,0,0,0,0,0,168,0,
0,0,0,0,1,0,0,0,0,0,0,0,20,0,0,0,
0,0,1,0,0,0,0,0,0,0,48,0,0,0,0,0,
1,0,0,0,0};
static const unsigned char qt_resource_names[] = {
0,
1,0,0,0,47,0,47,0,3,0,0,91,188,0,84,0,
117,0,108,0,11,4,105,214,60,0,84,0,117,0,108,0,
73,0,110,0,102,0,111,0,46,0,113,0,109,0,108,0,
7,11,191,88,156,0,84,0,117,0,108,0,46,0,113,0,
109,0,108,0,5,0,89,232,133,0,83,0,104,0,97,0,
114,0,101,0,15,2,95,26,220,0,80,0,97,0,105,0,
114,0,68,0,105,0,115,0,112,0,108,0,97,0,121,0,
46,0,113,0,109,0,108,0,9,0,40,229,188,0,83,0,
116,0,121,0,108,0,101,0,46,0,113,0,109,0,108,0,
9,9,101,209,28,0,69,0,114,0,114,0,111,0,114,0,
46,0,113,0,109,0,108,0,15,9,146,33,92,0,80,0,
111,0,105,0,110,0,116,0,115,0,84,0,97,0,98,0,
108,0,101,0,46,0,113,0,109,0,108,0,8,6,137,135,
7,0,83,0,112,0,97,0,114,0,114,0,105,0,110,0,
103,0,12,7,7,71,60,0,83,0,112,0,97,0,114,0,
114,0,105,0,110,0,103,0,46,0,113,0,109,0,108,0,
8,0,56,95,92,0,84,0,105,0,109,0,101,0,46,0,
113,0,109,0,108,0,16,7,224,90,28,0,83,0,112,0,
97,0,114,0,114,0,105,0,110,0,103,0,73,0,110,0,
102,0,111,0,46,0,113,0,109,0,108,0,8,8,1,90,
92,0,109,0,97,0,105,0,110,0,46,0,113,0,109,0,
108,0,10,4,111,210,66,0,79,0,117,0,116,0,77,0,
111,0,110,0,105,0,116,0,111,0,114,0,23,0,172,219,
220,0,83,0,112,0,97,0,114,0,114,0,105,0,110,0,
103,0,73,0,110,0,102,0,111,0,77,0,111,0,110,0,
105,0,116,0,111,0,114,0,46,0,113,0,109,0,108,0,
17,6,69,33,220,0,79,0,117,0,116,0,77,0,111,0,
110,0,105,0,116,0,111,0,114,0,84,0,117,0,108,0,
46,0,113,0,109,0,108,0,22,2,188,14,28,0,79,0,
117,0,116,0,77,0,111,0,110,0,105,0,116,0,111,0,
114,0,83,0,112,0,97,0,114,0,114,0,105,0,110,0,
103,0,46,0,113,0,109,0,108,0,10,11,239,190,131,0,
67,0,97,0,116,0,101,0,103,0,111,0,114,0,105,0,
101,0,115,0,22,11,204,181,124,0,80,0,97,0,114,0,
116,0,105,0,99,0,105,0,112,0,97,0,110,0,116,0,
115,0,87,0,105,0,110,0,100,0,111,0,119,0,46,0,
113,0,109,0,108,0,18,4,57,67,28,0,67,0,97,0,
116,0,101,0,103,0,111,0,114,0,121,0,87,0,105,0,
110,0,100,0,111,0,119,0,46,0,113,0,109,0,108};
static const unsigned char qt_resource_empty_payout[] = { 0, 0, 0, 0, 0 };
QT_BEGIN_NAMESPACE
extern Q_CORE_EXPORT bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
QT_END_NAMESPACE
namespace QmlCacheGeneratedCode {
namespace _0x5f_Categories_CategoryWindow_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Categories_ParticipantsWindow_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_OutMonitor_OutMonitorSparring_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__main_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Sparring_SparringInfo_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Share_PointsTable_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Share_Error_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Share_Style_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_OutMonitor_OutMonitorTul_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Tul_Tul_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Tul_TulInfo_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Sparring_Time_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_OutMonitor_SparringInfoMonitor_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Share_PairDisplay_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f_Sparring_Sparring_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/Categories/CategoryWindow.qml"), &QmlCacheGeneratedCode::_0x5f_Categories_CategoryWindow_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Categories/ParticipantsWindow.qml"), &QmlCacheGeneratedCode::_0x5f_Categories_ParticipantsWindow_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/OutMonitor/OutMonitorSparring.qml"), &QmlCacheGeneratedCode::_0x5f_OutMonitor_OutMonitorSparring_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/main.qml"), &QmlCacheGeneratedCode::_0x5f__main_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Sparring/SparringInfo.qml"), &QmlCacheGeneratedCode::_0x5f_Sparring_SparringInfo_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Share/PointsTable.qml"), &QmlCacheGeneratedCode::_0x5f_Share_PointsTable_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Share/Error.qml"), &QmlCacheGeneratedCode::_0x5f_Share_Error_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Share/Style.qml"), &QmlCacheGeneratedCode::_0x5f_Share_Style_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/OutMonitor/OutMonitorTul.qml"), &QmlCacheGeneratedCode::_0x5f_OutMonitor_OutMonitorTul_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Tul/Tul.qml"), &QmlCacheGeneratedCode::_0x5f_Tul_Tul_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Tul/TulInfo.qml"), &QmlCacheGeneratedCode::_0x5f_Tul_TulInfo_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Sparring/Time.qml"), &QmlCacheGeneratedCode::_0x5f_Sparring_Time_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/OutMonitor/SparringInfoMonitor.qml"), &QmlCacheGeneratedCode::_0x5f_OutMonitor_SparringInfoMonitor_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Share/PairDisplay.qml"), &QmlCacheGeneratedCode::_0x5f_Share_PairDisplay_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/Sparring/Sparring.qml"), &QmlCacheGeneratedCode::_0x5f_Sparring_Sparring_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.version = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
QT_PREPEND_NAMESPACE(qRegisterResourceData)(/*version*/0x01, qt_resource_tree, qt_resource_names, qt_resource_empty_payout);
}
const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qml)() {
    ::unitRegistry();
    Q_INIT_RESOURCE(qml_qmlcache);
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qml))
int QT_MANGLE_NAMESPACE(qCleanupResources_qml)() {
    Q_CLEANUP_RESOURCE(qml_qmlcache);
    return 1;
}
