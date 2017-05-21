function toggleReadMe(button) {
    var div = button.parentNode;
    var readme = div.childNodes[2];

    if (readme) {
        div.removeChild(readme);
    } else {
        var childDiv = document.createElement('div');
        readme = document.createElement('p');
        readme.textContent = "https://www.reddit.com/r/dailyprogrammer/comments/6bumxo/20170518_challenge_315_intermediate_game_of_life/";
        div.appendChild(childDiv);
        childDiv.appendChild(readme);
    }
}