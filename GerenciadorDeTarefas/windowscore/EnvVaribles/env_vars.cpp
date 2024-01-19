#ifdef _WIN32

#include "env_vars.h"

env_vars::env_vars() {}

void env_vars::setVariable(const std::string& key, const std::string& value) {
    variables[key] = value;
}

std::string env_vars::getVariable(const std::string& key) {
    auto it = variables.find(key);
    return (it != variables.end()) ? it->second : "";
}

void env_vars::removeVariable(const std::string& key) {
    variables.erase(key);
}

void env_vars::recoverVars() {
    QFile file("../GerenciadorDeTarefas/windowscore/EnvVaribles/Configs/env.json");
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        file.close();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        if (jsonDoc.isObject()) {
            QJsonObject jsonObject = jsonDoc.object();
            for (auto it = jsonObject.begin(); it != jsonObject.end(); ++it) {
                std::string chave = it.key().toStdString();
                std::string valor = it.value().toString().toStdString();
                variables[chave] = valor;
            }
        }
    }else {
        qDebug() << "Erro ao abrir o arquivo:" << file.errorString();
        qDebug() << "Erro ao abrir o arquivo:" << file.fileName();
    }
}


void env_vars::recordVars() {

    QJsonObject jsonObject;

    for (const auto& pair : variables) {
        QString chave(pair.first.c_str());
        jsonObject[chave] = QString::fromStdString(pair.second);
    }

    QJsonDocument jsonDocument(jsonObject);

    QFile file("../GerenciadorDeTarefas/windowscore/EnvVaribles/Configs/env.json");

    try{
        if(file.open(QIODevice::Text | QIODevice::WriteOnly)){
            QTextStream out(&file);
            out << jsonDocument.toJson();
            file.close();
        }
    }catch(const std::filesystem::filesystem_error& e){
        throw std::runtime_error("Erro ao salvar o arquivo");
    }
}

#endif
