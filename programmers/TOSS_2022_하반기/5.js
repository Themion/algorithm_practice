function getStylesOf(element, styles) {
    const answer = {};

    const addStyle = (style) => {
        if (styles[style] === undefined) return;
        Object.keys(styles[style]).forEach(
            (key) => (answer[key] = styles[style][key])
        );
    };

    /* 작성해주세요 */
    const tagName = element.elementType;
    const classNames = element.className
        .split(" ")
        .map((className) => `.${className}`);
    const id = `#${element.id}`;

    addStyle(tagName);
    classNames.forEach(addStyle);
    addStyle(id);

    return answer;
}

/* solution 함수는 수정하지 마세요. */
function solution(_element, _styles) {
    const element = JSON.parse(_element);
    const styles = JSON.parse(_styles);

    const result = getStylesOf(element, styles);

    return JSON.stringify(result, Object.keys(result).sort());
}

const style = getStylesOf(
    { elementType: "p", className: "text underline", id: "paragraph" },
    {
        "#paragraph": { color: "red" },
        ".text": {
            color: "grey",
            "font-size": "20px",
            "text-decoration": "none",
        },
        ".underline": {
            "text-decoration": "underline",
        },
        p: {
            color: "blue",
            "font-size": "16px",
            "line-height": "24px",
        },
    }
);

console.log(style);
