#include "UIAttrIntControl.h"

UIAttrIntControl::UIAttrIntControl(NDAttributeBase* attribute, QWidget* parent)
    :UICustomIntControl(parent)
{
    setAttribute(attribute);

    if (m_attribute == nullptr)
        return;

    QObject::connect(m_attribute, &NDIntAttribute::valueChanged, this, &UIAttrIntControl::onAttrValueChanged);
    QObject::connect(this, &UIAttrIntControl::valueChanged, this, &UIAttrIntControl::onControlValueChanged);
}

UIAttrIntControl::~UIAttrIntControl()
{

}

// 设置属性
void UIAttrIntControl::setAttribute(NDAttributeBase* attribute)
{
    if (attribute == nullptr || attribute->Type() != NDAttributeBase::t_int)
        return;

    m_attribute = qobject_cast<NDIntAttribute*>(attribute);
    if (m_attribute == nullptr)
        return;

    // 设置范围
    int min = 0, max = 0;
    m_attribute->getValueRange(min, max);
    this->setRangeValue(min, max);

    // 设置值
    this->setCurrentValue(m_attribute->getCurrentValue());
    this->setTagText(m_attribute->getDisplayName());
}

void UIAttrIntControl::onAttrValueChanged(int value)
{
    this->setCurrentValue(value);
}

void UIAttrIntControl::onControlValueChanged(int value)
{
    QObject::disconnect(m_attribute, &NDIntAttribute::valueChanged, this, &UIAttrIntControl::onAttrValueChanged);
    m_attribute->setCurrentValue(value);
    QObject::connect(m_attribute, &NDIntAttribute::valueChanged, this, &UIAttrIntControl::onAttrValueChanged);
}
