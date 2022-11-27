function solution(paths) {
    const answer = paths
        .join("/")
        .split("/")
        .reduce((prev, curr) => {
            switch (curr) {
                case "...":
                    prev.pop();
                case "..":
                    prev.pop();
                case ".":
                    return prev;
                default:
                    prev.concat(curr);
            }
        }, [])
        .join("/");

    return `/${answer}`;
}
