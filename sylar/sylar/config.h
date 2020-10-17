/**
 * @file config.h
 * @brief 配置模块
 * @author sylar.yin
 * @email 564628276@qq.com
 * @date 2019-05-22
 * @copyright Copyright (c) 2019年 sylar.yin All rights reserved (www.sylar.top)
 */ 
#ifndef __SYLAR_CONFIG_H__
#define __SYLAR_CONFIG_H__ 

#include <memory>
#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include <yaml-cpp/yaml.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>


namespace sylar {

/**
 * @brief 配置变量的基类
 */ 
class ConfigVarBase {
public:
    typedef std::shared_ptr<ConfigVarBase> ptr;
    /**
     * @brief 构造函数
     * @param[in] name 配置参数名称[0-9a-z_.]
     * @param[in] description 配置参数描述
     */ 
    ConfigVarBase(const std::string& name, const std::string& description = "")
        :m_name(name)
        ,m_description(description) {
        std::transform(m_name.begin(), m_name.end(), m_name.begin(), ::tolower);
    }

    /**
     * @brief 析构函数
     */ 
    virtual ~ConfigVarBase() {}

    /**
     * @brief 返回配置参数名称
     */ 
    const std::string& getName() const { return m_name; }

    /**
     * @brief 返回配置参数的描述
     */ 
    const std::string& getDescription() const { return m_description; }

    /**
     * @brief 转换成字符串
     */ 
    virtual std::string toString() = 0;

    /**
     * @brief 从字符串初始化值
     */ 
    virtual bool fromString(const std::string& val) = 0;

    /**
     * @brief 返回配置参数的类型名称
     */ 
    virtual std::string getTypeName() const = 0;
private:
    /// 配置参数的名称 
    std::string m_name;
    /// 配置参数的描述
    std::string m_description;
};

/**
 * @brief 类型转换模板类(F 源类型, T 目标类型)
 */ 
template<class F, class T>
class LexicalCast {
public:
    /**
     * @brief 类型转换
     * @brief[in] v 源类型值
     * @return 返回v转换后的目标类型
     * @exception 但类型不可转换是抛出异常
     */ 
    T operator()(const F& v) {
        return boost::lexical_cast<T>(v);
    }
};

/**
 * @brief 类型转换模板片特化(YAML String 转换成 std::vector<T>)
 */ 
template<class T>




}



#endif


