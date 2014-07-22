---
permalink: /tags/
title: Tags List
layout: default
---
<div id="post">
{% include tags.md %}

{% unless tags == empty %}
    <p>
    {% for tag in tags %}
        <a href="#{{ tag | cgi_escape }}">{{ tag }} <sup>{{ site.tags[tag] | size }}</sup></a>
        {% unless forloop.last %},{% endunless %}
    {% endfor %}
    </p>

    {% for tag in tags %}
        <h3 id="{{ tag | cgi_escape }}">{{ tag }}</h3>
        {% for chapter in (1..site.chapters) %}
            {% assign posts_exist = false %}
            {% for category in site.category_list %}
                {% for post in site.categories[category.name] %}
                    {% if post.chapter == chapter and post.tags contains tag %}
                        {% assign posts_exist = true %}
                    {% endif %}
                {% endfor %}
            {% endfor %}

            {% if posts_exist == true %}
                {% for category in site.category_list %}
                    {% for post in site.categories[category.name] %}
                        {% if post.chapter == chapter and post.tags contains tag %}
                        <h5>C{{ chapter }} &raquo;
                            <a href='{{ site.baseurl }}/{{ category.name }}'>{{ category.name | capitalize }}</a> &raquo;
                            <span class='date'>{{ post.date | date_to_string }}</span> &raquo;
                            <a href="{{ site.baseurl }}{{ post.url }}">{{ post.title }}</a></h5>
                        {% endif %}
                    {% endfor %}
                {% endfor %}
            {% endif %}
        {% endfor %}
    {% endfor %}
{% endunless %}
</div>
