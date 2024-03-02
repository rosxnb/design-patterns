#include <iostream>
#include <sstream>
#include <string>
#include <vector>


class HTMLBuilder;
class HTMLElement
{
    friend class HTMLBuilder;

    public:
        static HTMLBuilder init(const std::string& name);

        std::string str(size_t indent_size = 0) const;
        HTMLElement& replace_content(std::string content);
        HTMLElement& append_content(const std::string& content);
        HTMLElement& append_child(const HTMLElement& e);

    private:
        std::string m_name, m_content;
        std::vector<HTMLElement> m_childrens;
        constexpr static size_t indent_space = 2;

        HTMLElement(const std::string& name);
        HTMLElement(const std::string& name, const std::string& content);
};

class HTMLBuilder
{
    public:
        HTMLBuilder(HTMLElement root);
        HTMLBuilder(const std::string& name);
        HTMLBuilder& add_child(const HTMLElement& e);
        HTMLBuilder& add_child(const std::string& name, const std::string& content);
        std::string str() const;
        HTMLElement build();

    private:
        HTMLElement m_root;
};

int main()
{
    HTMLBuilder builder = HTMLElement::init("ul");
    builder.add_child("li", "This is list 1").add_child("li", "This is list 2").add_child("li", "This is list 3");

    std::cout << builder.str() << std::endl;
}

HTMLElement::HTMLElement(const std::string& name)
    : m_name{name}
{}

HTMLElement::HTMLElement(const std::string& name, const std::string& content)
    : m_name{name}, m_content{content}
{}

HTMLBuilder HTMLElement::init(const std::string& name)
{
    return {name};
}

std::string HTMLElement::str(size_t indent_size) const
{
    std::ostringstream oss;
    std::string indent_str(HTMLElement::indent_space * indent_size, ' ');

    oss << indent_str
        << '<' 
        << m_name
        << ">\n";

    if (m_content.length())
    {
        oss << std::string (HTMLElement::indent_space * (indent_size + 1), ' ')
            << m_content << "\n";
    }
    
    for (const HTMLElement& e: m_childrens)
    {
        oss << e.str(indent_size + 1);
    }

    oss << indent_str
        << "</"
        << m_name
        << ">\n";

    return oss.str();
}

HTMLElement& HTMLElement::replace_content(std::string content)
{
    m_content = content;
    return *this;
}

HTMLElement& HTMLElement::append_content(const std::string& content)
{
    m_content += content;
    return *this;
}

HTMLElement& HTMLElement::append_child(const HTMLElement& e)
{
    m_childrens.push_back(e);
    return *this;
}

HTMLBuilder::HTMLBuilder(HTMLElement root)
    : m_root{root}
{}

HTMLBuilder::HTMLBuilder(const std::string& name)
    : m_root{name}
{}

HTMLBuilder& HTMLBuilder::add_child(const HTMLElement& e)
{
    m_root.append_child(e);
    return *this;
}

HTMLBuilder& HTMLBuilder::add_child(const std::string& name, const std::string& content)
{
    m_root.append_child(HTMLElement{name, content});
    return *this;
}

std::string HTMLBuilder::str() const
{
    return m_root.str();
}

HTMLElement HTMLBuilder::build()
{
    return std::move(m_root);
}
